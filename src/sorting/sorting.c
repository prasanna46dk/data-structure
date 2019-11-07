#include"sorting/sorting.h"

void swapNum(int *arr, int i, int j)
{
  if (i != j) {
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
  }
}

void printArray(int *arr, int size)
{
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void bubbleSort(int *arr, int size)
{
  int i,j;
  for(i = 0; i < size-1; i++) {
    for(j = 1; j < size - i; j++) {
      if(arr[j - 1] > arr[j]) 
	swapNum(arr, j - 1, j);  
    }
  }
}

void mergeSort(int *arr, int first, int last)
{
  int mid;
  if(first < last) {
    mid = first + (last - first)/2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);
    merge(arr, first, mid, last);
  }
}

void merge(int *arr, int first, int mid, int last)
{
  int i,j,k;
  int temp[SIZE];
  i = first;
  j = mid + 1;
  k = 0;
  while(i <= mid && j <= last) {
      if(arr[i] < arr[j])
	  temp[k++] = arr[i++];
      else
	  temp[k++] = arr[j++];
  }
  while(i <= mid)
      temp[k++] = arr[i++];
  while(j <= last)
      temp[k++] = arr[j++];
  for(i = first, j = 0; i <= last;i++,j++)
    arr[i]=temp[j];
}

void quickSort(int *arr, int left, int right)
{
  int sortedIndex;
  if(left < right) {
    sortedIndex = partition(arr, left, right);
    quickSort(arr, left, sortedIndex - 1);
    quickSort(arr, sortedIndex + 1, right);
  }
}

int partition(int *arr, int left, int right)
{
  int i, j, pivot;
  pivot = arr[right];
  i = left-1;
  for(j = left; j < right; j++) {
    if(pivot > arr[j]) {
      i++;
      swapNum(arr, i, j);
    }
  }
  swapNum(arr, i+1, right);
  return (i+1);
}
