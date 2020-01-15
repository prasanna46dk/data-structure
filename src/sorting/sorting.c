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

  for(i = 0; i < leftSize; i++)
    leftArr[i] = arr[start+i];

  for(j = 0; j < rightSize; j++)
    rightArr[j] = arr[mid+1+j];

  for(i = 0, j = 0, k = start;
      i < (leftSize) &&
	j < (rightSize);
      k++) {

    if(leftArr[i] < rightArr[j]) {
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
}
