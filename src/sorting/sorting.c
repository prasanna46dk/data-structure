#include"sorting/sorting.h"

<<<<<<< HEAD
void swap(int *a, int *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void display(int *arr)
{
  int i;
  for(i = 0; i < SIZE; i++)
    printf("%d ", arr[i]);
}
void bubbleSort(int *arr)
{
  int i,j;
  for(i = 0; i< SIZE - 1; i++) {
    for(j = 1; j < SIZE - i; j++) {
      if(arr[j - 1] > arr[j]) {
	arr[j-1] ^=arr[j];
	arr[j] ^=arr[j-1];
	arr[j-1] ^=arr[j];
	//swap(&arr[j - 1], &arr[j]);
      }
=======
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
>>>>>>> 0aa619f921367b91c2b4d39d8deb006f72e8c839
    }
  }
}

<<<<<<< HEAD
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

void quickSort(int *arr, int first, int last)
{
  int sortedIndex;
  if(first < last) {
    sortedIndex = divide(arr, first, last);
    quickSort(arr, first, sortedIndex - 1);
    quickSort(arr, sortedIndex + 1, last);
  }
}

int divide(int *arr, int first, int last)
{
  int i, j, pivot;
  pivot = first;
  i = first + 1;
  j = last;
  while(1) {
    while(arr[pivot] > arr[i])
      i++;
    while(arr[pivot] <= arr[j])
      j--;
    if(i < j)
      swap(&arr[i], &arr[j]);
    else {
      swap(&arr[pivot], &arr[j]);
      return j;
    }
  }
=======
void merge(int *arr, int start, int mid, int end)
{
  int
    leftSize  = mid-start+1,
    rightSize = end-mid,
    leftArr[leftSize],
    rightArr[rightSize],
    i,
    j,
    k;

  memcpy(leftArr, )
  for(i = 0; i < (leftSize); i++)
    leftArr[i] = arr[start+i];

  for(j = 0; j < (start - mid); i++)
    rightArr[j] = arr[mid+j];

  for(i = 0, j = 0, k = start;
       i < (leftSize) &&
	 j < (rightSize);
       k++) {

    if(
       // leftArr[i] != INT_MAX &&
       // rightArr[i] != INT_MAX &&
       leftArr[i] <= rightArr[j]) {
      arr[k] = leftArr[i++];
    } else {
      arr[k] = rightArr[j++];
    }
  }

  while(i < leftSize)
      arr[k++] = leftArr[i++];

  while(j < rightSize)
      arr[k++] = rightArr[j++];
}

void mergeSort(int *arr, int start, int end)
{
  int mid;
  if(start < end) {
    mid = start + (end - start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
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
    if(arr[j] < pivot) {
      i++;
      swapNum(arr, i, j);
    }
  }
  swapNum(arr, i+1, right);
  return (i+1);
>>>>>>> 0aa619f921367b91c2b4d39d8deb006f72e8c839
}
