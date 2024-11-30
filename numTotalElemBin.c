#include <stdio.h>

int main() {
    const char *filename = "../trabalho/seed/seed_01.dat";

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fclose(file);

    printf("Tamanho do arquivo: %ld bytes\n", fileSize);
    printf("Numero total de elementos (int): %ld\n", fileSize / sizeof(int));
    return 0;
}
