#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10
#define RANGE 25
//buble sort
void bubbleSort (int arr[]);

//merge sort
void mergeSort  (int arr[], int first, int last);
void merge      (int arr[], int first, int mid, int last);

//quick sort
int  divide     (int arr[], int first, int last);
void quickSort  (int arr[], int first, int last);

void display    (int arr[]);
void swap       (int *a, int *b);
