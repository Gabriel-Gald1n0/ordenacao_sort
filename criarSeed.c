#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMEROS 100

// Armazenando as informações de um aluno
typedef struct {
    int valor;
} NUM;


void geraSeed(NUM *seed);

int main(void) {
    FILE *fp;
    NUM Seed;
    int i = 0;

    srand(time(NULL));

    // abre um arquivo binário para escrita
    fp = fopen("seed_01.dat", "wb");

    if (fp == NULL) {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }

    
    do {
        size_t ok;
        geraSeed(&Seed);  
        ok = fwrite(&Seed, sizeof(NUM), 1, fp);  
        if (ok != 1)
            printf("Problemas na escrita");
    } while (++i < NUMEROS); 

    fclose(fp); 
    return 0;
}

void geraSeed(NUM *seed) {
    seed->valor = (rand() % 99) + 1;  // Atribui um valor aleatório entre 1 e 99
}
