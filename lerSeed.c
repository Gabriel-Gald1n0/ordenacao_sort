#include <stdio.h>
#include <stdlib.h>
#define NUMEROS 100

typedef struct
{
    int valor;
} NUM;


int main(void)
{
    FILE *fp;
    NUM *Seed;
    int i = 0;
    Seed = malloc(NUMEROS * sizeof(NUM));

    fp = fopen("seed_01.dat", "rb");
    
    if(fp == NULL) 
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }

    // lendo os alunos guardados no arquivo
    for(i = 0; i < NUMEROS; i++)
    {
        size_t ok;
        ok = fread(&Seed[i], sizeof(NUM), 1, fp); 
        if (ok != 1)
            printf("Problemas na leitura");
        else
        {
            printf("%d ", Seed[i].valor);

        }
    }

    return 0; 
}