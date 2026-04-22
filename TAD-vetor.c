#include "TAD-vetor.h"
#include <stdlib.h> 
#include <stdio.h>

struct vetor {
    int dados[TAM];
};

// Cria vetor ordenado sem repetição 

Vetor* cria(int incremento) {
    Vetor* v = (Vetor*) malloc(sizeof(Vetor));

    if (v == NULL) {
        printf("Erro de memoria!\n");
        exit(1);
    }

    v->dados[0] = rand() % 10;

    for (int i = 1; i < TAM; i++) {
        v->dados[i] = v->dados[i-1] + incremento;
    }

    return v;
}

// Libera 
void libera(Vetor* v) {
    free(v);
}

// Acessa
int acessa(Vetor* v, int pos) {
    if (pos < 0 || pos >= TAM) {
        printf("Posicao invalida!\n");
        exit(1);
    }
    return v->dados[pos];
}

// Busca sequencial
int buscaSequencial(Vetor* v, int chave) {
    for (int i = 0; i < TAM; i++) {
        if (v->dados[i] == chave)
            return i;
    }
    return -1;
}

// Busca binária
int buscaBinaria(Vetor* v, int chave) {
    int inicio = 0, fim = TAM - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (v->dados[meio] == chave)
            return meio;
        else if (v->dados[meio] < chave)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

//QUESTAO 3

void gerarVetor(Vetor* v) {
    for (int i = 0; i < TAM; i++) {
        v->dados[i] = rand() % (TAM * 10);
    }
}

void copiarVetor(Vetor* origem, Vetor* destino) {
    for (int i = 0; i < TAM; i++) {
        destino->dados[i] = origem->dados[i];
    }
}


void bubbleSort(Vetor* v, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v->dados[j] > v->dados[j + 1]) {
                int temp = v->dados[j];
                v->dados[j] = v->dados[j + 1];
                v->dados[j + 1] = temp;
            }
        }
    }
}

void insertionSort(Vetor* v, int n) {
    for (int i = 1; i < n; i++) {
        int chave = v->dados[i];
        int j = i - 1;
        while (j >= 0 && v->dados[j] > chave) {
            v->dados[j + 1] = v->dados[j];
            j--;
        }
        v->dados[j + 1] = chave;
    }
}

void selectionSort(Vetor* v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        
        for (int j = i + 1; j < n; j++) {
            if (v->dados[j] < v->dados[min]) min = j;
        }
        int temp = v->dados[i];
        v->dados[i] = v->dados[min];
        v->dados[min] = temp;
    }
}

static int particionar(Vetor* v, int inicio, int fim) {
    int pivo = v->dados[fim];
    int i = inicio - 1;
    
    for (int j = inicio; j < fim; j++) {
        if (v->dados[j] < pivo) {
            i++;
            int temp = v->dados[i];
            v->dados[i] = v->dados[j];
            v->dados[j] = temp;
        }
    }
    int temp = v->dados[i + 1];
    v->dados[i + 1] = v->dados[fim];
    v->dados[fim] = temp;
    return i + 1;
}

void quickSort(Vetor* v, int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(v, inicio, fim);
        quickSort(v, inicio, p - 1);
        quickSort(v, p + 1, fim);
    }
}

static void merge(Vetor* v, int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = 0;
    
    int *temp = (int *)malloc((fim - inicio + 1) * sizeof(int));
    
    while (i <= meio && j <= fim) {
        if (v->dados[i] < v->dados[j]) 
        temp[k++] = v->dados[i++];
        else 
        temp[k++] = v->dados[j++];
    }
    
    while (i <= meio) 
    temp[k++] = v->dados[i++];
    while (j <= fim) 
    temp[k++] = v->dados[j++];
    for (i = inicio, k = 0; i <= fim; i++, k++) 
    v->dados[i] = temp[k];
    free(temp);
}

void mergeSort(Vetor* v, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}
