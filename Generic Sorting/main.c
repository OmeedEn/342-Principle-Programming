#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"
#include "quickSort.h"

int main()
{
    printf("This is the Mergsort:\n");
    int m1[] = {2,3,5,6,9,10,28,15,13,17,10,11,8,7,1};
    int m1_n = sizeof(m1)/sizeof(m1[0]);

    printf("Test1: \n");
    printf("unsorted array: ");
    for(int i=0; i<m1_n; i++)
    {
        printf("%d ", m1[i]);
    }
    
    mergeSort(m1, m1_n);
    printf("\nsorted array: ");
    for(int i=0; i<m1_n; i++)
    {
        printf("%d ", m1[i]);
    }

    printf("\n");
    printf("\nTest2: \n");
    int m2[] = {9,459,2,45,0,3};
    int m2_n = sizeof(m2)/sizeof(m2[0]);

    printf("unsorted array: ");
    for(int i=0; i<m2_n; i++)
    {
        printf("%d ", m2[i]);
    }
    
    mergeSort(m2, m2_n);
    printf("\nsorted array: ");
    for(int i=0; i<m2_n; i++)
    {
        printf("%d ", m2[i]);
    }

    printf("\n");
    printf("\nTest3: Empty List\n");
    int m3[] = {};
    int m3_n = sizeof(m3)/sizeof(m3[0]);

    printf("unsorted array: ");
    for(int i=0; i<m3_n; i++)
    {
        printf("%d ", m3[i]);
    }
    
    mergeSort(m3, m3_n);
    printf("\nsorted array: ");
    for(int i=0; i<m3_n; i++)
    {
        printf("%d ", m3[i]);
    }
    
    printf("\n");
    printf("\nQuickSort:");
    int q1[] = {3, 4, 12, 6, 9, 2, 16, 10, 8, 23, 43, 67, 7};
    int q1_n = sizeof(q1) / sizeof(q1[0]);
    
    printf("\nTest1: \n");
    printf("unsorted array: ");
    for(int i=0; i<q1_n;i++)
    {
        printf("%d ", q1[i]);
    }
    
    quick_sort(q1, q1_n);
    printf("\nsorted array: ");
    for(int i=0; i<q1_n; i++)
    {
        printf("%d ", q1[i]);
    }

    printf("\n");
    int q2[] = {3, 42, 122, 1, 9, 22, 16,};
    int q2_n = sizeof(q2) / sizeof(q2[0]);
    
    printf("\nTest2: \n");
    printf("unsorted array: ");
    for(int i=0; i<q2_n;i++)
    {
        printf("%d ", q2[i]);
    }
    
    quick_sort(q2, q2_n);
    printf("\nsorted array: ");
    for(int i=0; i<q2_n; i++)
    {
        printf("%d ", q2[i]);
    }

    printf("\n");
    printf("\nTest3: Empty List");
    int q3[] = {};
    int q3_n = sizeof(q3) / sizeof(q3[0]);
    
    printf("\nunsorted array: ");
    for(int i=0; i<q3_n;i++)
    {
        printf("%d ", q3[i]);
    }
    
    quick_sort(q3, q3_n);
    printf("\nsorted array: ");
    for(int i=0; i<q3_n; i++)
    {
        printf("%d ", q3[i]);
    }

    return 0;
}
