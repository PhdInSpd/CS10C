#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


const int WINDOWS = 0;
const int MAC = 1;

/* You should spend some time playing with these constants to try out different size arrays.
    If SIZE is big, you probably want to set PRINT_VALUES to false.  Make sure MAX_NUMBER is
    big enough so you don't have a lot of repeated numbers in the array.  I've provided two
    interesting examples of how to set the constants.
*/
/*
const bool PRINT_VALUES = true;
const int MAX_NUMBER = 999;
const int SIZE = 12;
*/

const int SYSTEM = WINDOWS;     // set this to WINDOWS or MAC in order to get the correct units 
                                // when timing the sorts (milliseconds vs. seconds)
const bool PRINT_VALUES = false;
const int MAX_NUMBER = INT_MAX - 1;
//const int SIZE = 50000;
//const int SIZE = 8; // works for harden
//const int SIZE = 16; // works
//const int SIZE = 32; // works
//const int SIZE = 1024; // works
//const int SIZE = 1024 * 50; // fails
//const int SIZE = 1024 * 25; // fails
//const int SIZE = 1024 * 12; // fails
//const int SIZE = 1024 * 6; // fails
//const int SIZE = 1024 * 3; // works
//const int SIZE = 1024 * 5;   // fails
//const int SIZE = 1024 * 4;  // fails
const int SIZE = 1024 * 4000;
int mainlist[SIZE] = {};
int list[SIZE] = {};

void print(clock_t elapsed, const int list[], int numItems);
void copy(const int from[], int to[], int numItems);
void fill(int list[], int numItems);
int partition(int a[], int left, int right);
void quicksort(int list[], int start, int end);
int partitionQtA(int a[], int left, int right);
void quicksortQtA(int list[], int start, int end);
void bubblesort(int list[], int numItems);
void bubblesort2(int list[], int numItems);
void selectionsort(int list[], int numItems);
void insertionsort(int list[], int numItems);
void merge(int list[], int start, int end);
void mergesort(int list[], int start, int end);
void heapsort(int list[], int numItems);
void convertToHeap(int list[], int numItems);
int parent(int k);
int leftChild(int k);
int rightChild(int k);
bool isleaf(int k, int numItems);
void reheapifyDown(int list[], int numItems);
bool verifySort(int list[], int numItems);
int main() {
   
    clock_t start, stop;

    long fails = 0;
    long pass = 0;
    srand(static_cast<unsigned>(time(nullptr)));
    while (true) {
        fill(mainlist, SIZE);
        std::cout << "done filling" << std::endl;
        if (PRINT_VALUES) {
            std::cout << "original list: ";
            print(0, mainlist, SIZE);
            std::cout << std::endl;
        }

        copy(mainlist, list, SIZE);
        std::cout << "quicksortQtA: ";
        start = clock();
        quicksortQtA(list, 0, SIZE - 1);
        stop = clock();
        print(stop - start, list, SIZE);
        if (!verifySort(list, SIZE)) {
            fails++;
            std::cout << "quickSortQtA fails :" << fails << std::endl;
        }
        else {
            pass++;
            std::cout << "quickSortQtA pass :" << pass << std::endl;
        }

        copy(mainlist, list, SIZE);
        std::cout << "quicksort: ";
        start = clock();
        quicksort(list, 0, SIZE - 1);
        stop = clock();
        print(stop - start, list, SIZE);
        if (!verifySort(list, SIZE)) {
            fails++;
            std::cout << "quickSort fails :" << fails << std::endl;
        }
        else {
            pass++;
            std::cout << "quickSort pass :" << pass << std::endl;
        }
       
    }
    
    copy(mainlist, list, SIZE);
    std::cout << "bubble   : ";
    start = clock();
    bubblesort(list, SIZE);
    stop = clock();
    print(stop - start, list, SIZE);

    copy(mainlist, list, SIZE);
    std::cout << "bubble 2 : ";
    start = clock();
    bubblesort2(list, SIZE);
    stop = clock();
    print(stop - start, list, SIZE);

    copy(mainlist, list, SIZE);
    start = clock();
    std::cout << "selection: ";
    selectionsort(list, SIZE);
    stop = clock();
    print(stop - start, list, SIZE);
    /*
        copy(mainlist, list, SIZE);
        start = clock();
        std::cout << "insertion: ";
        insertionsort(list, SIZE);
        stop = clock();
        print(stop - start, list, SIZE);

        copy(mainlist, list, SIZE);
        start = clock();
        std::cout << "merge    : ";
        mergesort(list, 0, SIZE-1);
        stop = clock();
        print(stop - start, list, SIZE);

        copy(mainlist, list, SIZE);
        std::cout << "heap     : ";
        start = clock();
        heapsort(list, SIZE);
        stop = clock();
        print(stop - start, list, SIZE);

        
    */

    return 0;

}

/// <summary>
/// verify sofrt is increasing order
/// </summary>k
/// <param name="list"></param>
/// <param name="numItems"></param>
/// <returns></returns>
bool verifySort(int list[], int numItems) {
    if (numItems < 2) return true;
    for (size_t i = 0; i < numItems-1; i++) {
        if (list[i] > list[i + 1]) {
            return false;
        }
    }
    return true;
}



void fill(int list[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        list[i] = rand() % (MAX_NUMBER + 1);
    }
}



std::string toString(int num) {
    std::string result;
    if (num < 10) {
        result += "00";
    }
    else if (num < 100) {
        result += "0";
    }
    result += std::to_string(num);
    return result;
}

void print(clock_t elapsed, const int list[], int numItems) {
    if (PRINT_VALUES) {
        for (int i = 0; i < numItems; i++) {
            std::cout << list[i] << " ";
        }
        std::cout << std::endl;
    }

    //   std::cout << "time elapsed: " << elapsed << std::endl;

    std::cout << "time elapsed: " << elapsed / 1000 << "." << toString(elapsed % 1000);
    if (SYSTEM == MAC) std::cout << " milliseconds." << std::endl;
    if (SYSTEM == WINDOWS) std::cout << " seconds." << std::endl;

}






void copy(const int from[], int to[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        to[i] = from[i];
    }
}







/*****************************************************************

            BUBBLE SORT 1

*****************************************************************/

void bubblesort(int list[], int numItems) {
    int i, j;

    for (i = 0; i < numItems - 1; i++) {
        for (j = 0; j < numItems - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                std::swap(list[j], list[j + 1]);
            }
        }
    }
}








/*****************************************************************

            BUBBLE SORT 2

*****************************************************************/

void bubblesort2(int list[], int numItems) {
    int i, j;
    bool didswap = true;

    i = 0;
    while (i < numItems - 1 && didswap) {
        didswap = false;
        for (j = 0; j < numItems - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                std::swap(list[j], list[j + 1]);
                didswap = true;
            }
        }

        i++;
    }
}






/*****************************************************************

            SELECTION SORT

*****************************************************************/

void selectionsort(int list[], int numItems) {
    int i, j, index;
    int largest;

    for (int i = 0; i < numItems - 1; i++) {
        int indexOfSmallest = i;
        for (int j = i + 1; j < numItems; j++) {
            if (list[j] < list[indexOfSmallest]) {
                indexOfSmallest = j;
            }
        }

        std::swap(list[i], list[indexOfSmallest]);
    }
}





/*****************************************************************

            INSERTION SORT

*****************************************************************/

void insertionsort(int list[], int numItems) {

    int j;

    for (int i = 1; i < numItems; i++) {
        j = i;
        while (list[j] < list[j - 1] && j > 0) {
            std::swap(list[j], list[j - 1]);
            j--;
        }
    }
}







/*****************************************************************

            MERGE SORT

*****************************************************************/

void mergesort(int list[], int start, int end)
{
    if (start < end) {
        mergesort(list, start, (start + end) / 2);
        mergesort(list, (start + end) / 2 + 1, end);
        merge(list, start, end);
    }
}



void merge(int list[], int start, int end)
{
    int* temp = new int[end + 1];
    int mid = (start + end) / 2;

    int count = start; // pointer to new (merged) list
    int left = start;  // pointer to left half of list
    int right = mid + 1;  // pointer to right half
    while (left <= mid && right <= end) {
        if (list[left] <= list[right]) {
            temp[count] = list[left];
            left++;
        }
        else {
            temp[count] = list[right];
            right++;
        }
        count++;
    }
    while (left <= mid) {
        temp[count] = list[left];
        count++;
        left++;
    }
    while (right <= end) {
        temp[count] = list[right];
        count++;
        right++;
    }
    for (count = start; count <= end; count++) {
        list[count] = temp[count];
    }
    delete[] temp;
}









/*****************************************************************

            QUICKSORT

*****************************************************************/

void quicksort(int list[], int left, int right)
{
    if (left < right) {
        int pivot = partition(list, left, right);
        quicksort(list, left, pivot - 1);
        quicksort(list, pivot + 1, right);
    }
}

void quicksortQtA(int list[], int left, int right)
{
    if (left < right) {
        int pivot = partitionQtA(list, left, right);
        quicksortQtA(list, left, pivot - 1);
        quicksortQtA(list, pivot + 1, right);
    }
}










int partition(int list[], int left, int right) {
    int pivot = list[right];
    int indexFromRight = right - 1;
    int indexFromLeft = left;
    while (indexFromLeft < indexFromRight) {
        while (list[indexFromLeft] <= pivot && indexFromLeft < indexFromRight) {
            indexFromLeft++;
        }

        while (list[indexFromRight] >= pivot && indexFromLeft < indexFromRight) {
            indexFromRight--;
        }
      
        if (indexFromLeft < indexFromRight) {
            std::swap(list[indexFromLeft], list[indexFromRight]);
        }
    }
  
    if (list[indexFromLeft] > list[right]) {
        std::swap(list[indexFromLeft], list[right]);
        return indexFromLeft;
    }
    return right;
}


int partitionQtA(int list[], int left, int right) {
    int indexPivot;
    int indexFromRight = right - 1;
    int indexFromLeft = left;

    int members = right - left + 1;
    if ( members >= 3 ) {
        // bubble sort left,middle and right
        int middle = (left + right) / 2;
        if (list[left] > list[middle]) {
            std::swap(list[left], list[middle]);
        }
        if (list[middle] > list[right]) {
            std::swap(list[middle], list[right]);
        }
        if (list[left] > list[middle]) {
            std::swap(list[left], list[middle]);
        }
        if (members == 3) {
            return middle;
        }

        // place middle pivot in the right
        std::swap(list[middle], list[right]);
        indexFromLeft++;
    }
    int pivot = list[right];

   
    while (indexFromLeft < indexFromRight) {
        while (list[indexFromLeft] <= pivot && indexFromLeft < indexFromRight) {
            indexFromLeft++;
        }

        while (list[indexFromRight] >= pivot && indexFromLeft < indexFromRight) {
            indexFromRight--;
        }

        if (indexFromLeft < indexFromRight) {
            std::swap(list[indexFromLeft], list[indexFromRight]);
            indexFromLeft++;
            indexFromRight--;
        }
    }

    // move indexFromLeft till we find insert location
    bool found = false;
    indexPivot = right;;
    while (!found && indexFromLeft < right) {
        if (list[indexFromLeft] > pivot) {
            found = true;
            indexPivot = indexFromLeft;
        }
        else {
            indexFromLeft++;
        }
    }

    if (found) {
        std::swap(list[indexFromLeft], list[right]);
    }
    
    return indexPivot;
}



















/*****************************************************************

            HEAP SORT

*****************************************************************/


void heapsort(int list[], int numItems)
{
    int numUnsorted = numItems;

    convertToHeap(list, numItems);
    while (numUnsorted > 1) {
        numUnsorted--;
        std::swap(list[0], list[numUnsorted]);
        reheapifyDown(list, numUnsorted);
    }
}



void convertToHeap(int list[], int numItems)
{
    for (int i = 1; i < numItems; i++) {
        int k = i;
        while (k != 0 && list[k] > list[parent(k)]) {
            std::swap(list[k], list[parent(k)]);
            k = parent(k);
        }
    }
}


int parent(int k)
{
    return (k - 1) / 2;
}


int leftChild(int k)
{
    return 2 * k + 1;
}



int rightChild(int k)
{
    return 2 * k + 2;
}




bool isleaf(int k, int numItems)
{
    return leftChild(k) >= numItems;
}



void reheapifyDown(int list[], int numItems)
{
    int current = 0;
    int bigChildIndex;
    bool heapOK = false;


    while (!heapOK && !isleaf(current, numItems)) {
        bigChildIndex = leftChild(current);
        if (rightChild(current) < numItems && list[rightChild(current)] > list[bigChildIndex]) {
            bigChildIndex = rightChild(current);
        }

        if (list[current] < list[bigChildIndex]) {
            std::swap(list[current], list[bigChildIndex]);
            current = bigChildIndex;
        }
        else {
            heapOK = true;
        }
    }
}


