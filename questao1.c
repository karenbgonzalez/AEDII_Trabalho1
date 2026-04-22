
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "TAD-vetor.h"

#define EXEC 30


volatile int forcarExecucao; 

double calcularDesvio(double tempos[], int n, double media) {
    double somaVar = 0;
    for (int i = 0; i < n; i++) {
        somaVar += pow(tempos[i] - media, 2);
    }
    return sqrt(somaVar / n);
}

int main() {
    srand(time(NULL));

    Vetor* v = cria(0); 
    gerarVetor(v); 

    double tSeq[EXEC], tBin[EXEC];
    double somaSeq = 0, somaBin = 0;

    for (int i = 0; i < EXEC; i++) {
        int chave;
        if (i < 15) chave = acessa(v, rand() % TAM);
        else chave = rand() % (TAM * 10);

        int repeticoes = 1000; // repetimos 1000 vezes para tentar fazer otempo aparecer melhor
        clock_t inicio = clock();
        for (int r = 0; r < repeticoes; r++) {
            forcarExecucao = buscaSequencial(v, chave);
        }
        clock_t fim = clock();
        

        tSeq[i] = (((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0) / repeticoes;
        somaSeq += tSeq[i];
    }

    quickSort(v, 0, TAM - 1); 

   
    for (int i = 0; i < EXEC; i++) {
        int chave;
        if (i < 15) chave = acessa(v, rand() % TAM);
        else chave = rand() % (TAM * 10);

        int repeticoes = 10000; 
        clock_t inicio = clock();
        for (int r = 0; r < repeticoes; r++) {
            forcarExecucao = buscaBinaria(v, chave);
        }
        clock_t fim = clock();
        
        tBin[i] = (((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0) / repeticoes;
        somaBin += tBin[i];
    }

    
    printf("EXECUCOES (ms):\n");
    for (int i = 0; i < EXEC; i++) {
        printf("Execucao %d: Seq = %.6f | Bin = %.6f\n", i + 1, tSeq[i], tBin[i]);
    }
  
    double mS = somaSeq / EXEC;
    double mB = somaBin / EXEC;
       
    printf("RESULTADOS QUESTAO 1\n");
    printf("Busca Sequencial: Media %.6f ms e Desvio %.6f ms\n", mS, calcularDesvio(tSeq, EXEC, mS));
    printf("Busca Binaria:    Media %.6f ms e Desvio %.6f ms\n", mB, calcularDesvio(tBin, EXEC, mB));

    libera(v);
    return 0;
}
