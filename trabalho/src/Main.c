#include "biblioteca.h"

int main() {
    int sizes[] = {100, 1000, 10000};
    int i, size;
    const char *filenames[] = {"../seed/seed_01.dat", "../seed/seed_02.dat", "../seed/seed_03.dat"}; 

    // Variáveis para contagem de tempo
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);  // Obtém a frequência do contador

    // Loop para cada tamanho
    for (i = 0; i < 3; i++) {
        size = sizes[i];
        int *array = (int *)malloc(size * sizeof(int));

        // Verifica se malloc foi bem-sucedido
        if (array == NULL) {
            printf("Falha na alocação de memória para o array de tamanho %d\n", size);
            exit(1);  
        }

        // Lê o array do arquivo binário
        readArrayFromFile(array, size, filenames[i]);
        
        printf("Tamanho do Array: %d\n", size);
        
        // Quick Sort
        int *tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Falha na alocação de memória para tempArray (Quick Sort) com tamanho %d\n", size);
            free(array);
            exit(1);
        }
        copyArray(array, tempArray, size);

        QueryPerformanceCounter(&start);  // Marca o início
        quickSort(tempArray, 0, size - 1);
        QueryPerformanceCounter(&end);  // Marca o fim
        printf("Quick Sort: %.6f segundos\n", (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart);
        free(tempArray);

        // Bubble Sort
        tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Falha na alocação de memória para tempArray (Bubble Sort) com tamanho %d\n", size);
            free(array);
            exit(1);
        }
        copyArray(array, tempArray, size);

        QueryPerformanceCounter(&start);  // Marca o início
        bubbleSort(tempArray, size);
        QueryPerformanceCounter(&end);  // Marca o fim
        printf("Bubble Sort: %.6f segundos\n", (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart);
        free(tempArray);

        // Shell Sort
        tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Falha na alocação de memória para tempArray (Shell Sort) com tamanho %d\n", size);
            free(array);
            exit(1);
        }
        copyArray(array, tempArray, size);

        QueryPerformanceCounter(&start);  // Marca o início
        shellSort(tempArray, size);
        QueryPerformanceCounter(&end);  // Marca o fim
        printf("Shell Sort: %.6f segundos\n", (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart);
        free(tempArray);

        // Heap Sort
        tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Falha na alocação de memória para tempArray (Heap Sort) com tamanho %d\n", size);
            free(array);
            exit(1);
        }
        copyArray(array, tempArray, size);

        QueryPerformanceCounter(&start);  // Marca o início
        heapSort(tempArray, size);
        QueryPerformanceCounter(&end);  // Marca o fim
        printf("Heap Sort: %.6f segundos\n", (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart);
        free(tempArray);

        free(array);
        printf("\n");
    }
    return 0;
}
