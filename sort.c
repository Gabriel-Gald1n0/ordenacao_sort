
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Quick Sort
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

// Bubble Sort
void bubbleSort(int arr[], int n);

// Shell Sort
void shellSort(int arr[], int n);

// Heap Sort
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);

// Helper Functions
void generateArray(int arr[], int n);
void printArray(int arr[], int n);
void copyArray(int source[], int dest[], int n);

int main() {
    int sizes[] = {100, 1000, 10000};
    int i, size;

    // Loop through each size
    for (i = 0; i < 3; i++) {
        size = sizes[i];
        int *originalArray = (int *)malloc(size * sizeof(int));
        int *array = (int *)malloc(size * sizeof(int));
        
        // Generate random array
        generateArray(originalArray, size);
        
        printf("Array Size: %d\n", size);
        
        // Quick Sort
        copyArray(originalArray, array, size);
        clock_t start = clock();
        quickSort(array, 0, size - 1);
        clock_t end = clock();
        printf("Quick Sort: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        // Bubble Sort
        copyArray(originalArray, array, size);
        start = clock();
        bubbleSort(array, size);
        end = clock();
        printf("Bubble Sort: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        // Shell Sort
        copyArray(originalArray, array, size);
        start = clock();
        shellSort(array, size);
        end = clock();
        printf("Shell Sort: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        // Heap Sort
        copyArray(originalArray, array, size);
        start = clock();
        heapSort(array, size);
        end = clock();
        printf("Heap Sort: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        free(originalArray);
        free(array);
        printf("\n");
    }
    return 0;
}

// Quick Sort Implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Bubble Sort Implementation
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Shell Sort Implementation
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Heap Sort Implementation
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// Helper Functions
void generateArray(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}
