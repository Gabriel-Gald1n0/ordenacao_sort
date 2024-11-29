#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototypes
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void bubbleSort(int arr[], int n);
void shellSort(int arr[], int n);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void readArrayFromFile(int arr[], int n, const char *filename);  // New function
void copyArray(int source[], int dest[], int n);

int main() {
    int sizes[] = {100, 1000, 10000};
    int i, size;
    const char *filenames[] = {"seed_01.dat", "seed_02.dat", "seed_03.dat"}; 

    // Loop through each size
    for (i = 0; i < 3; i++) {
        size = sizes[i];
        int *array = (int *)malloc(size * sizeof(int));

        // Check if malloc was successful
        if (array == NULL) {
            printf("Memory allocation failed for array size %d\n", size);
            exit(1);  // Exit if memory allocation fails
        }

        // Read array from binary file
        readArrayFromFile(array, size, filenames[i]);
        
        printf("Array Size: %d\n", size);
        
        // Quick Sort
        int *tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Memory allocation failed for tempArray (Quick Sort) for size %d\n", size);
            free(array);
            exit(1);
        }
        copyArray(array, tempArray, size);
        clock_t start = clock();
        quickSort(tempArray, 0, size - 1);
        clock_t end = clock();
        printf("Quick Sort: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
        free(tempArray);

        // Bubble Sort
        tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Memory allocation failed for tempArray (Bubble Sort) for size %d\n", size);
            free(array);
            exit(1);
        }
        copyArray(array, tempArray, size);
        start = clock();
        bubbleSort(tempArray, size);
        end = clock();
        printf("Bubble Sort: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
        free(tempArray);

        // Shell Sort
        tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Memory allocation failed for tempArray (Shell Sort) for size %d\n", size);
            free(array);
            exit(1);
        }
        copyArray(array, tempArray, size);
        start = clock();
        shellSort(tempArray, size);
        end = clock();
        printf("Shell Sort: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
        free(tempArray);

        // Heap Sort
        tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Memory allocation failed for tempArray (Heap Sort) for size %d\n", size);
            free(array);
            exit(1);
        }
        copyArray(array, tempArray, size);
        start = clock();
        heapSort(tempArray, size);
        end = clock();
        printf("Heap Sort: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
        free(tempArray);

        free(array);
        printf("\n");
    }
    return 0;
}

// Read data from binary file
void readArrayFromFile(int arr[], int n, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    size_t readSize = fread(arr, sizeof(int), n, file);
    if (readSize != (size_t)n) {
        printf("Error reading file %s. Expected %d elements, but read %lu.\n", filename, n, (unsigned long)readSize);
        exit(1);
    }
    fclose(file);

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
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}
