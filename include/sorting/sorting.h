#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define SIZE 20
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
