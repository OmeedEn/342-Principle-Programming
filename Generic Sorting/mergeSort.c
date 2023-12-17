#include <stdio.h>
#include <stdlib.h>

// calling the recursive function
void msort(int *a, int length);
// recursive function to begin merge sort
void msort_rec(int *a, int left, int right);
// merge the sorted arrays
void msorted(int *a, int left, int middle, int right);

int main()
{
  int nums[] = {3, 5, 4, 0, 8, 2};
  int length = sizeof(nums)/sizeof(nums[0]); //Calculates the array size 

  //Checks for empty input
  if (length <= 0)
  {
    printf("Invalid input.");
    return 1;
  }
  msort(nums, length);


  //Prints the result 
  for (int i = 0; i < length; i++)
  {
    printf("%d ", nums[i]);
  }
  printf("\n");

  return 0;
}

void msort(int *a, int length)
{
  if(length <= 1)
  {
    return;
  }
  msort_rec(a, 0, length - 1); //recursive 
}

//recursive function 
void msort_rec(int *a, int left, int right) 
{
  if (left < right)
  {
    int middle = left + (right - left) / 2;

    msort_rec(a, left, middle);
    msort_rec(a, middle + 1, right);

    msorted(a, left, middle, right);
  }
}

//Merges the left and the right of the array
void msorted(int *a, int left, int middle, int right)
{
  int left_len = middle - left + 1;
  int right_len = right - middle;

  //malloc is for the memory allocation 
  int *temp_left = (int *)malloc(left_len * sizeof(int));
  int *temp_right = (int *)malloc(right_len * sizeof(int));

  int i, j, k;

  for (int i = 0; i < left_len; i++)
  {
    temp_left[i] = a[left + i];
  }
  for (int i = 0; i < right_len; i++)
  {
    temp_right[i] = a[middle + 1 + i];
  }

  for (i = 0, j = 0, k = left; k <= right; k++)
  {
    if ((i < left_len) && (j >= right_len || temp_left[i] <= temp_right[j]))
    {
      a[k] = temp_left[i];
      i++;
    }
    else
    {
      a[k] = temp_right[j];
      j++;
    }
  }
  free(temp_left);
  free(temp_right);
}