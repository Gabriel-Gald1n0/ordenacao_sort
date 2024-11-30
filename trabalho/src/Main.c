#include "biblioteca.h"

int main() {
    int sizes[] = {100, 1000, 10000};
    int i, size;
    const char *filename = "seed/seed_01.dat"; 
    int totalSize = 10000;  

    // Aloca memória para o array completo
    int *fullArray = (int *)malloc(totalSize * sizeof(int));
    if (fullArray == NULL) {
        printf("Falha na alocação de memória para o array principal.\n");
        return 1;
    }

    // Lê o arquivo completo para o array principal
    readArrayFromFile(fullArray, totalSize, filename);

    // Número de repetições para medir o tempo com mais precisão
    int repetitions = 10;
    printf("Numero de Repeticoes:  %d\n\n", repetitions);

    // Loop para cada tamanho
    for (i = 0; i < 3; i++) {
        size = sizes[i];
        printf("Tamanho do Array: %d\n", size);

        
        clock_t start, end;

        // Quick Sort
        int *tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Falha na alocação de memória para tempArray (Quick Sort) com tamanho %d\n", size);
            free(fullArray);
            return 1;
        }
        copyArray(fullArray, tempArray, size);

        start = clock();
        for (int j = 0; j < repetitions; j++) {
            quickSort(tempArray, 0, size - 1);
        }
        end = clock();
        printf("Quick Sort: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC / repetitions);
        free(tempArray);

        // Bubble Sort
        tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Falha na alocação de memória para tempArray (Bubble Sort) com tamanho %d\n", size);
            free(fullArray);
            return 1;
        }
        copyArray(fullArray, tempArray, size);

        start = clock();
        for (int j = 0; j < repetitions; j++) {
            bubbleSort(tempArray, size);
        }
        end = clock();
        printf("Bubble Sort: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC / repetitions);
        free(tempArray);

        // Shell Sort
        tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Falha na alocação de memória para tempArray (Shell Sort) com tamanho %d\n", size);
            free(fullArray);
            return 1;
        }
        copyArray(fullArray, tempArray, size);

        start = clock();
        for (int j = 0; j < repetitions; j++) {
            shellSort(tempArray, size);
        }
        end = clock();
        printf("Shell Sort: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC / repetitions);
        free(tempArray);

        // Heap Sort
        tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Falha na alocação de memória para tempArray (Heap Sort) com tamanho %d\n", size);
            free(fullArray);
            return 1;
        }
        copyArray(fullArray, tempArray, size);

        start = clock();
        for (int j = 0; j < repetitions; j++) {
            heapSort(tempArray, size);
        }
        end = clock();
        printf("Heap Sort: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC / repetitions);
        free(tempArray);

        printf("\n");
    }

    free(fullArray);
    return 0;
}
