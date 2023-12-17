#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdio.h>
#include <stdlib.h>

// calling the recursive function
void msort(int *a, int length);
// recursive function to begin merge sort
void msort_rec(int *a, int left, int right);
// merge the sorted arrays
void msorted(int *a, int left, int middle, int right);

#endif // MERGESORT_H
