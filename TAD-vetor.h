// TAD: Vetor 
#ifndef VETOR_H
#define VETOR_H

#define TAM 1000000

// Tipo exportado
typedef struct vetor Vetor;

// Cria vetor
Vetor* cria(int incremento);

// Libera memória
void libera(Vetor* v);

// Acessa valor de uma posição
int acessa(Vetor* v, int pos);

// Função Busca Sequencial: percorre os elementos de uma lista linearmente até encontrar o elemento 
int buscaSequencial(Vetor* v, int chave);

// Função Busca Binária: divide repetidamente uma lista ordenada ao meio, comparando o elemento do meio com a chave e descartando metade dos elementos a cada passo, até encontrar o elemento procurado
int buscaBinaria(Vetor* v, int chave);

// Vetor (Questão 3 Trab1 AEDII)
void gerarVetor(Vetor* v);
void copiarVetor(Vetor* origem, Vetor* destino);

// Ordenações
void bubbleSort(Vetor* v, int n);
void insertionSort(Vetor* v, int n);
void selectionSort(Vetor* v, int n);
void quickSort(Vetor* v, int inicio, int fim);
void mergeSort(Vetor* v, int inicio, int fim);

#endif // VETOR_H