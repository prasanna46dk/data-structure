#include"sorting/sorting.h"

int main() {
  int arr[SIZE], temp_arr[SIZE], i = 0;
<<<<<<< HEAD
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
=======

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

>>>>>>> 0aa619f921367b91c2b4d39d8deb006f72e8c839
  return 0;
}
