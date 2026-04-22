#include <stdio.h>
#include <stdlib.h>
#include "TAD-lista.h"

tipoNo* criarNo(int val, tipoNo* prox) {  
    tipoNo* novo = malloc(sizeof(tipoNo));
   
    novo -> valor = val;
    novo -> prox = prox;
    return novo;
}

void iniciarLista(tipoLista *lista){
    lista->prim=NULL;
    lista->ult = NULL;
    lista->tamanho = 0;
}

void apagarLista(tipoLista *lista){
    tipoNo* atual = lista->prim;
   
    while(atual != NULL){
        tipoNo* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->prim = NULL;
    lista->ult = NULL;
    lista->tamanho = 0;
}   

void inserirLista(tipoLista* lista, int valor) {
    tipoNo* novo = criarNo(valor, NULL);
    
    if (lista->prim == NULL) {    
        lista->prim = novo;
        lista->ult = novo;
    } else {
        lista->ult->prox = novo;       
        lista->ult = novo;    
    }
}

int buscaSequencialLista(tipoLista* lista, int chave){
    tipoNo* atual = lista->prim;
    
    while(atual != NULL){
        if(atual->valor == chave) return 1; 
        atual = atual->prox; 
    }
    return 0; 
}

