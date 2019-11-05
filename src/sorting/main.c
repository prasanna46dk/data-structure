#include"sorting/sorting.h"

int main() {
  int arr[SIZE], temp_arr[SIZE], i = 0;
  for(i = 0; i < SIZE; i++)
    arr[i] = temp_arr[i] = rand() % RANGE;
  printf("Array:\n");
  display(arr);
  printf("\n");
  printf("Bubble Sort\n");
  bubbleSort(arr);
  display(arr);
  printf("\n");
  memcpy(arr, temp_arr, sizeof(arr));
  printf("Quick Sort\n");
  quickSort(arr, 0, SIZE - 1);
  display(arr);
  printf("\n");
  memcpy(arr, temp_arr, sizeof(arr));
  mergeSort(arr, 0, SIZE - 1);
  printf("Merge Sort\n");
  display(arr);
  printf("\n");
  memcpy(arr, temp_arr, sizeof(arr));
  return 0;
}
