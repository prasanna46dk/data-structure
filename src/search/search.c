#include<stdio.h>

#define SIZE 8
#define ELEMENT 5

int linearSearch(int[], int);
int binSearch(int[], int, int, int);
void bubbleSort(int[]);
int main()
{
  int arr[SIZE] = {3, 7, 11, 78, 34, 12, 5, 90}, i, index;
  printf("Array:\n");
  for(i = 0; i< SIZE; i++)
    printf("%d ", arr[i]);

  index = linearSearch(arr, 0);
  if(index == -1)
    printf("\nElement %d not found\n", ELEMENT);
  else
    printf("\nElement %d found at index %d\n", ELEMENT, index);
  printf("After Sorting\n");
  bubbleSort(arr);
  for(i = 0; i< SIZE; i++)
    printf("%d ", arr[i]);

  index = binSearch(arr, ELEMENT, 0, SIZE - 1);
  if(index == -1)
    printf("\nElement %d not found\n", ELEMENT);
  else
    printf("\nElement %d found at index %d\n", ELEMENT, index);

  return 0;
}

int binSearch(int arr[], int n, int first, int last)
{
  int mid;
  if(first < last)
    {
      mid = (first +last)/2;
      if(n == arr[first])
	return first;
      if(n == arr[last])
	return first;
      if(n == arr[mid])
	return mid;
      if(arr[first] < n && n < arr[mid])
	binSearch(arr, n, first, mid);
      else if(arr[mid] < n && n < arr[last])
	binSearch(arr, n, mid + 1, last);
    }
  else
    return -1;
}

int linearSearch(int arr[],int i)
{
  int len = sizeof(arr);
  //int i = 0;
  if(arr[i] == ELEMENT)
    return i;
  if(i < len)
    linearSearch(arr, i + 1);
    /*
  for(i = 0; i < len; i++)
    if(arr[i] == n)
      return i;
  */
  else
    return -1;
}

void bubbleSort(int arr[])
{
  int len = sizeof(arr);
  int i,j;
  for(i = 0; i< len - 1; i++) {
    for(j = 1; j < len - i; j++) {
      if(arr[j - 1] > arr[j])
	{
	  arr[j - 1] ^= arr[j];
	  arr[j] ^= arr[j - 1];
	  arr[j - 1] ^= arr[j];
	}
    }
  }
}
