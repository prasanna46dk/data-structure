#include"sorting.h"

int main() {
  int arr[SIZE], temp_arr[SIZE], i = 0;
  for(i = 0; i < SIZE; i++)
    arr[i] = temp_arr[i] = rand() % 10;
  bubbleSort(arr);
  display(arr);
  memcpy(arr, temp_arr, sizeof(arr));
  quickSort(arr, 0, SIZE - 1);
  display(arr);
  memcpy(arr, temp_arr, sizeof(arr));
  mergeSort(arr, 0, SIZE - 1);
  display(arr);
  memcpy(arr, temp_arr, sizeof(arr));
  return 0;
}
