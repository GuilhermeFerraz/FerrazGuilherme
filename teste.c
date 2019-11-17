#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "FilaPrioridadeHeap.h"
//#include "FilaPrioridadeEncadeada.h"
#include "FilaPrioridadeCircular.h"

FilaPrioridade* medeTempo(int n, FilaPrioridade* (*funcao)(int)){
    clock_t inicio, fim, total; 
    inicio = clock(); 
    FilaPrioridade* f = funcao(n);   
    fim = clock();
    total = fim - inicio;
    double tempoExecutado = ((double)total)/CLOCKS_PER_SEC; // in seconds 
    printf("[%d]: %f\n", n, tempoExecutado);
    return f;
}

void medeTempoR(int n, FilaPrioridade* f, Boolean (*funcao)(FilaPrioridade*, Tipo*)){
    int x, removido;
    clock_t inicio, fim, total; 
    inicio = clock();
    while(fila_tamanho(f) > 0){
        funcao(f, &removido);    
    }
    fim = clock();
    total = fim - inicio;
    double tempoExecutado = ((double)total)/CLOCKS_PER_SEC; // in seconds 
    printf("\n[%d] Removido: %f\n", n, tempoExecutado);

   
}

FilaPrioridade* filaAleatoria(int tam){
    FilaPrioridade* f = fila_criar(tam);
    int i;
    srand(time(NULL));
    for(i=0; i<tam; i++){
        fila_inserir(f, rand() % (tam*10));
    }
    return f;
}


int main(){
    int tam = 1000000;
    
    FilaPrioridade* f = medeTempo(tam,&filaAleatoria);
    medeTempoR(tam,f,&fila_remover);
    
}