#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10
#define RANGE 25

//buble sort
void bubbleSort(int *arr, int size);

//merge sort
void mergeSort(int *arr, int first, int last);
void merge      (int *arr, int first, int mid, int last);

//quick sort
int  partition(int *arr, int first, int last);
void quickSort(int *arr, int first, int last);

void printArray(int *arr, int size);
void swapNum(int *arr, int i, int j);
