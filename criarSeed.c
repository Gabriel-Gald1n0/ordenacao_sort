#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMEROS 10000 // Altere sempre o tamanho de NUMEROS pra quando for ler uma seed

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
    fp = fopen("seed_01.dat", "wb"); // // altere seu nome também para criar

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
    seed->valor = (rand() % (100000 - 1)) + 1;  // Atribui um valor aleatório 
}
