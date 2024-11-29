#include "biblioteca.h"

int main() {
    int sizes[] = {100, 1000, 10000};
    int i, size;
    const char *filenames[] = {"../seed/seed_01.dat", "../seed/seed_02.dat", "../seed/seed_03.dat"}; 

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

        // Número de repetições para medir o tempo com mais precisão
        int repetitions = 10;
        clock_t start, end;

        // Quick Sort
        int *tempArray = (int *)malloc(size * sizeof(int));
        if (tempArray == NULL) {
            printf("Falha na alocação de memória para tempArray (Quick Sort) com tamanho %d\n", size);
            free(array);
            exit(1);
        }
        copyArray(array, tempArray, size);

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
            free(array);
            exit(1);
        }
        copyArray(array, tempArray, size);

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
            free(array);
            exit(1);
        }
        copyArray(array, tempArray, size);

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
            free(array);
            exit(1);
        }
        copyArray(array, tempArray, size);

        start = clock();
        for (int j = 0; j < repetitions; j++) {
            heapSort(tempArray, size);
        }
        end = clock();
        printf("Heap Sort: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC / repetitions);
        free(tempArray);

        free(array);
        printf("\n");
    }
    return 0;
}
