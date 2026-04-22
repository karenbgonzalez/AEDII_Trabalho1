#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "TAD-vetor.h"
#include "TAD-lista.h"

#define EXEC 30

volatile int forcarExecucao;

double calcularDesvio(double tempos[], int n, double media) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += pow(tempos[i] - media, 2);
    }
    return sqrt(soma / n);
}

int main() {
    srand(time(NULL));

    Vetor* v = cria(3); 
    tipoLista lista;
    iniciarLista(&lista);
   
    for (int i = 0; i < TAM; i++) {
        inserirLista(&lista, acessa(v, i));
    }

    double temposVetor[EXEC];
    double temposLista[EXEC];
    int chaves[EXEC];

    
    for (int i = 0; i < EXEC; i++) {
       
        if (i < 15) {
            chaves[i] = acessa(v, rand() % TAM); 
        } else {
            chaves[i] = rand() % (TAM * 10);   
        }
    }

    for (int i = 0; i < EXEC; i++) {
        
        int repeticoes = 100; 
        clock_t inicio = clock();
        for (int r = 0; r < repeticoes; r++) {
            forcarExecucao = buscaSequencial(v, chaves[i]);
        }
   
        temposVetor[i]=((double)(clock() - inicio)/CLOCKS_PER_SEC)/repeticoes;
    }

    for (int i = 0; i < EXEC; i++) {
        
        int repeticoes = 10; 
        clock_t inicio = clock();
        for (int r = 0; r < repeticoes; r++) {
            forcarExecucao = buscaSequencialLista(&lista, chaves[i]);
        }
        temposLista[i] = ((double)(clock() - inicio) / CLOCKS_PER_SEC) / repeticoes;
    }

    printf("EXECUCOES (ms):\n");
    for (int i = 0; i < EXEC; i++) {
        
        printf("Execucao %d: Vetor = %.6f | Lista = %.6f\n", 
                i + 1, temposVetor[i] * 1000.0, temposLista[i] * 1000.0);
        }
    
        printf("\n");

    double somaV = 0, somaL = 0;
    for (int i = 0; i < EXEC; i++) {
        somaV += temposVetor[i];
        somaL += temposLista[i];
    }
    double mediaVetor = somaV / EXEC;
    double mediaLista = somaL / EXEC;

    printf("RESULTADOS QUESTAO 2\n");
    printf("Busca no Vetor: Media %.6f ms e Desvio %.6f ms\n", mediaVetor * 1000, calcularDesvio(temposVetor, EXEC, mediaVetor) * 1000); 
    printf("Busca na Lista: Media %.6f ms e Desvio %.6f ms\n", mediaLista * 1000, calcularDesvio(temposLista, EXEC, mediaLista) * 1000); 
    printf("Diferenca das Medias: %.6f ms\n", (mediaLista - mediaVetor) * 1000);

    apagarLista(&lista);
    libera(v);

    return 0;
}
