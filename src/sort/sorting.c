#include"sorting.h"


void display(int arr[])
{
  int i;
  for(i = 0; i < SIZE; i++)
    printf("%d", arr[i]);
}
void bubbleSort(int arr[])
{
  int len = sizeof(arr);
  int i,j;
  for(i = 0; i< len - 1; i++) {
    for(j = 1; j < len - i; j++) {
      if(arr[j - 1] > arr[j]) {
	arr[j - 1] ^= arr[j];
	arr[j] ^= arr[j - 1];
	arr[j - 1] ^= arr[j];
      }
    }
  }
}

void mergeSort(int arr[], int first, int last)
{
  int mid;
  if(first < last) {
    mid = first + (last - first)/2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);
    merge(arr, first, mid, last);
  }
}

void merge(int arr[], int first, int mid, int last)
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

void quickSort(int arr[], int first, int last)
{
  int sortedIndex;
  if(first < last) {
    sortedIndex = divide(arr, first, last);
    quickSort(arr, first, sortedIndex - 1);
    quickSort(arr, sortedIndex + 1, last);
  }
}

int divide(int arr[], int first, int last)
{
  int i, j, pivot;
  pivot = i = first;
  j = last - 1;
  while(1) {
    while(pivot <= i)
      i++;
    while(pivot > j)
      j++;
    if(i <= j) {
      i ^= j;
      j ^= i;
      i ^= j;
    }
    else {
      pivot ^= j;
      j ^= pivot;
      pivot ^= j;
      return j;
    }
  }
}
