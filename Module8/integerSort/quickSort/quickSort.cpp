// https://www.youtube.com/watch?v=Hoixgm4-P4M
#include <iostream>
#include <vector>


// Sorts theArray[first..last].
void quickSort(std::vector<int>& theArray, int first , int last ) {
    if (first < last) {
        /*Choose a pivot item p from theArray[first..last]
        Partition the items of theArray[first..last] about p*/
        int pivotIndex = last;

        // The partition is theArray[first..pivotIndex..last]
        quickSort(theArray, first, pivotIndex - 1) // Sort S 1
        quickSort(theArray, pivotIndex + 1, last) // Sort S 2
    }
// If first >= last, there is nothing to do
