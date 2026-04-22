#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 
#include "TAD-vetor.h"

#define RODADAS 10
#define N 100000 

double calcularDesvio(double tempos[], int n, double media) {
    double somaVar = 0;
    for (int i = 0; i < n; i++) {
        somaVar += pow(tempos[i] - media, 2);
    }
    return sqrt(somaVar / n);
}

int main() {
    srand(time(NULL));

    Vetor* original = cria(0); 
    Vetor* teste = cria(0); 

    double somaBubble = 0, somaInsertion = 0, somaSelection = 0, somaQuick = 0, somaMerge = 0;
    double tB[RODADAS], tI[RODADAS], tS[RODADAS], tQ[RODADAS], tM[RODADAS];

    printf("QUESTAO 3 (%d elementos)\n\n", N);

    for (int r = 0; r < RODADAS; r++) {
        printf("Rodada %d: Gerando novos valores\n", r + 1);
        
        // Gera valores aleatórios novos para esta rodada
        
        gerarVetor(original);

        //Bubble Sort

        copiarVetor(original, teste);
        clock_t t = clock();
        bubbleSort(teste, N);
        tB[r] = (double)(clock() - t) / CLOCKS_PER_SEC;
        somaBubble += tB[r];
        printf("  Bubble Sort:    %.4f s\n", tB[r]);

        //Insertion Sort

        copiarVetor(original, teste);
        t = clock();
        insertionSort(teste, N);
        tI[r] = (double)(clock() - t) / CLOCKS_PER_SEC;
        somaInsertion += tI[r];
        printf("  Insertion Sort: %.4f s\n", tI[r]);

        //Selection Sort

        copiarVetor(original, teste);
        t = clock();
        selectionSort(teste, N);
        tS[r] = (double)(clock() - t) / CLOCKS_PER_SEC;
        somaSelection += tS[r];
        printf("  Selection Sort: %.4f s\n", tS[r]);

        // Quick Sort

        copiarVetor(original, teste);
        t = clock();
        quickSort(teste, 0, N - 1);
        tQ[r] = (double)(clock() - t) / CLOCKS_PER_SEC;
        somaQuick += tQ[r];
        printf("  Quick Sort:     %.4f s\n", tQ[r]);

        // Merge Sort

        copiarVetor(original, teste);
        t = clock();
        mergeSort(teste, 0, N - 1);
        tM[r] = (double)(clock() - t) / CLOCKS_PER_SEC;
        somaMerge += tM[r];
        printf("  Merge Sort:     %.4f s\n", tM[r]);
    }

    double mediaBubble = somaBubble / RODADAS;
    double mediaInsertion = somaInsertion / RODADAS;
    double mediaSelection = somaSelection / RODADAS;
    double mediaQuick = somaQuick / RODADAS;
    double mediaMerge = somaMerge / RODADAS;

    printf("RESULTADOS QUESTAO 3\n");
    printf("Bubble Sort:    Media %.4f s e Desvio %.4f s\n", mediaBubble, calcularDesvio(tB, RODADAS, mediaBubble));
    printf("Insertion Sort: Media %.4f s e Desvio %.4f s\n", mediaInsertion, calcularDesvio(tI, RODADAS, mediaInsertion));
    printf("Selection Sort: Media %.4f s e Desvio %.4f s\n", mediaSelection, calcularDesvio(tS, RODADAS, mediaSelection));
    printf("Quick Sort:     Media %.4f s e Desvio %.4f s\n", mediaQuick, calcularDesvio(tQ, RODADAS, mediaQuick));
    printf("Merge Sort:     Media %.4f s e Desvio %.4f s\n", mediaMerge, calcularDesvio(tM, RODADAS, mediaMerge));

    free(original);
    free(teste);
    return 0;
}
