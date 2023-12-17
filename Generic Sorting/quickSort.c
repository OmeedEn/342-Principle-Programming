/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

/***
 * We recursively perform 3 steps:
 * 1. Bring the pivot to its appropiate position such that left of the pivot is smaller and right is larger
 * 2. Quick sort the left part
 * 3. Quick sort the right part.
 ***/
void quick_sort(int *a, int n); // quick sort an array a with n elements in C

int partition(int arr[], int low, int high);
void swap(int *, int *);
void quickSort(int *, int low, int high);
int main()
{

    int arr[] = {3, 4, 12, 6, 9, 2, 16, 10, 8, 23, 43, 67, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("unsorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    quick_sort(arr, n);
    printf("\nsorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

int partition(int *a, int low, int high)
{
    int pivot = high;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// n is the elenments of the array
void quick_sort(int *a, int n)
{
    quickSort(a, 0, n - 1);
}