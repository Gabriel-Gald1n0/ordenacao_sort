#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void bubbleSort(int arr[], int n);
void shellSort(int arr[], int n);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void readArrayFromFile(int *arr, int totalSize, const char *filename);
void copyArray(int source[], int dest[], int n);

#endif
