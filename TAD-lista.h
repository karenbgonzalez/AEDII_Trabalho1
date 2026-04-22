#ifndef LISTA_H
#define LISTA_H

typedef struct No { 
    int valor;
    struct No *prox;
} tipoNo;

typedef struct Lista {
    tipoNo  *prim;      // primeiro nó da lista    
    tipoNo  *ult;       // último nó
    int  tamanho;   // quantidade de elementos              
} tipoLista;

//Operações para realização da questão 2

void iniciarLista (tipoLista *l);           // aloca e inicializa uma nova lista

void apagarLista (tipoLista *l);         // libera a memória alocada para a lista

void inserirLista (tipoLista *l, int valor);   // insere um novo nó no final da lista, com os mesmos valores do vetor da questão 1

int  buscaSequencialLista(tipoLista *l, int chave);   // busca sequencial, retorna 1 se encontrou, 0 caso contrário
 
#endif