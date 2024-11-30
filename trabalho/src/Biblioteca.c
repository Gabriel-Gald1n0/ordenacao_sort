#include "biblioteca.h"

// bubble Sort
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

// Heap Sort
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
    int largest = i;        // Inicializa o maior como raiz
    int left = 2 * i + 1;   // Filho esquerdo
    int right = 2 * i + 2;  // Filho direito

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
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

// Quick Sort Implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivo = (arr[low] + arr[high] + arr[(low+high)/2])/3;
    
    while(low < high){
        while(arr[low] <= pivo && low < high)
            low++;
        while(arr[high] > pivo && low < high)
            high--;

        if(low < high){
            int aux = arr[low];
            arr[low] = arr[high];
            arr[high] = aux;
        }
    }

    int aux = arr[low];
    arr[low] = arr[high];
    arr[high] = aux;

    return high;
}

// Funções De Ajuda
void copyArray(int origin[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = origin[i];
    }
}

// Lendo Informações dos arquivos binarios
void readArrayFromFile(int *arr, int totalSize, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    size_t readSize = fread(arr, sizeof(int), totalSize, file);
    fclose(file);

    if (readSize != (size_t)totalSize) {
        printf("Erro ao ler o arquivo %s. Esperado %d elementos, mas foram lidos %lu.\n",
               filename, totalSize, (unsigned long)readSize);
        exit(1);
    }

}


