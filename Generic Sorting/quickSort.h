#ifndef QUICKSORT_H
#define QUICKSORT_H

/***
 * We recursively perform 3 steps:
 * 1. Bring the pivot to its appropriate position such that the left of the pivot is smaller and the right is larger
 * 2. Quick sort the left part
 * 3. Quick sort the right part.
 ***/

// Function to perform Quick Sort on an array
void quick_sort(int *a, int n);

#endif // QUICKSORT_H