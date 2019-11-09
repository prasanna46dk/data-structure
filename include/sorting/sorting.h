#include<stdio.h>
#include<stdlib.h>
#include<string.h>
<<<<<<< HEAD

#define SIZE 10
#define RANGE 25
//buble sort
void bubbleSort (int *arr);

//merge sort
void mergeSort  (int *arr, int first, int last);
void merge      (int *arr, int first, int mid, int last);

//quick sort
int  divide     (int *arr, int first, int last);
void quickSort  (int *arr, int first, int last);

void display    (int *arr);
void swap       (int *a, int *b);
=======
#include<limits.h>
#define SIZE 3
#define RANGE 25

// buble sort
void bubbleSort(int *arr, int size);

// merge sort
void mergeSort(int *arr, int first, int last);
void merge      (int *arr, int first, int mid, int last);

// quick sort
int  partition(int *arr, int start, int end);
void quickSort(int *arr, int start, int end);

void printArray(int *arr, int size);
void swapNum(int *arr, int i, int j);
>>>>>>> 0aa619f921367b91c2b4d39d8deb006f72e8c839
