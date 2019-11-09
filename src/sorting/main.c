#include"sorting/sorting.h"

int main() {
  int arr[SIZE], temp_arr[SIZE], i = 0;

  for(i = 0; i < SIZE; i++)
    arr[i] = temp_arr[i] = rand() % RANGE;

  printf("Original Array\n");
  printArray(arr, SIZE);

  printf("\nBubble Sort\n");
  bubbleSort(arr, SIZE);
  printArray(arr, SIZE);

  memcpy(arr, temp_arr, sizeof(arr));

  printf("\nQuick Sort\n");
  quickSort(arr, 0, SIZE-1);
  printArray(arr, SIZE);

  memcpy(arr, temp_arr, sizeof(arr));

  printf("\nMerge Sort\n");
  mergeSort(arr, 0, SIZE - 1);
  printArray(arr, SIZE);

  return 0;
}
