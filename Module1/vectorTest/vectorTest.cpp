
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

const int ARRAY_SIZE = 25;

template <class T>
void sort(T list[], int numItems);

template <class T>
int indexOfSmallest(const T list[], int startingIndex, int numItems);

void print(vector<int>& v);
void testVector();
void testTemplateFunction();

//int main() {
//    testTemplateFunction();
//    testVector();
//    return 0;
//}

void testVector() {


    vector<int> v;
    int currentSize;

    for (int i = 0; i < 20; i++) {
        v.push_back(i);

        currentSize = v.size();
        cout << "size: " << currentSize << " capacity: " << v.capacity() << endl;
    }

    print(v);
}



void print(vector<int>& printMe) {
    for (int i = 0; i < printMe.size(); i++) {
        cout << printMe.at(i) << " ";
    }
    cout << endl;

    for (int i = 0; i < printMe.size(); i++) {
        cout << printMe[i] << " ";
    }
    cout << endl;

    // cout << printMe.at(150) << endl;
}



void testTemplateFunction() {
    srand(static_cast<unsigned> (time(nullptr)));

    int list[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        list[i] = rand() % 1000;
    }

    sort(list, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    string stringList[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        stringList[i] = "";
        int stringlength = rand() % 6 + 1;
        for (int j = 0; j < stringlength; j++) {
            stringList[i] = stringList[i] + char(rand() % 26 + 'a');
        }
    }

    sort(stringList, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << stringList[i] << " ";
    }
    cout << endl;
}


template <class T>
void sort(T list[], int numItems)
{
    for (int count = 0; count < numItems - 1; count++) {
        swap(list[indexOfSmallest(list, count, numItems)],
            list[count]);
    }

}


template <class T>
int indexOfSmallest(const T list[], int startingIndex, int numItems)
{
    int targetIndex = startingIndex;

    for (int count = startingIndex + 1; count < numItems; count++) {
        if (list[count] < list[targetIndex]) {
            targetIndex = count;
        }
    }

    return targetIndex;
}