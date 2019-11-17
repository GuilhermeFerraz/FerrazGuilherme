
#include <stdio.h>
#include <stdlib.h>


typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

/************************************************
 * ESTRUTURA
 ***********************************************/ 

typedef struct{
    Tipo* vetor;
    int tam;
    int qtde;    
}FilaPrioridade;


/************************************************
 * PROTOTIPOS
 ***********************************************/ 
FilaPrioridade* fila_criar(int tam);
void fila_destruir(FilaPrioridade* f);

Boolean fila_inserir(FilaPrioridade* f, Tipo elemento);
Boolean fila_remover(FilaPrioridade* f, Tipo* endereco);

Boolean fila_primeiro(FilaPrioridade* f, Tipo* endereco);
int fila_tamanho(FilaPrioridade* f);
int fila_contem(FilaPrioridade* f, Tipo elemento);
void fila_imprimir(FilaPrioridade* f);

//FUNCOES AUXILIARES
void troca(Tipo* a, Tipo* b);
int pai(int i);
int filhoEsquerda(int i);
int filhoDireita(int i);
void sobeHeap(FilaPrioridade* f, int k);
void desceHeap(FilaPrioridade* f, int k);

/************************************************
 * IMPLEMENTACAO
 ***********************************************/ 

FilaPrioridade* fila_criar(int tam){
    FilaPrioridade* novo = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    novo->vetor = (int*)calloc(tam,sizeof(int));
    novo->tam = tam;
    novo->qtde = 0;
    return novo;
}

Boolean fila_inserir(FilaPrioridade* f, Tipo elemento){
    if(f == NULL) return false;
    if(f->qtde >= f->tam) return false;

    f->vetor[f->qtde] = elemento;
    f->qtde++;
    sobeHeap(f, f->qtde-1);

    return true;   

}

Boolean fila_remover(FilaPrioridade* f, Tipo* endereco){
    if(f == NULL) return false;
    if(f->qtde == 0) return false;

    *endereco = f->vetor[0];
    f->vetor[0] = f->vetor[f->qtde-1];
    f->qtde--;
    desceHeap(f, 0);
    
    return true;
}

int fila_tamanho(FilaPrioridade* f){
    return f->qtde;
}


// FUNCOES AUXILIARES

void troca(Tipo* a, Tipo* b){
    Tipo temp = *a;
    *a = *b;
    *b = temp;
}

int pai(int i){
    return (i-1)/2;
}

int filhoEsquerda(int i){
    return 2*i+1;
}
int filhoDireita(int i){
    return 2*i+2;
}

void sobeHeap(FilaPrioridade* f, int k){
    if(f->vetor[k] > f->vetor[pai(k)]){
        // troca(&(f->vetor[k]), &(f->vetor[pai(k)]))
        troca(f->vetor+k, f->vetor + pai(k));
        sobeHeap(f, pai(k));
    }
}

// outra versao
// void sobeHeap(FilaPrioridade* f, int k){
//     if(f->vetor[k] <= f->vetor[pai(k)]) return;
    
//     // troca(&(f->vetor[k]), &(f->vetor[pai(k)]))
//     troca(f->vetor+k, f->vetor + pai(k));
//     sobeHeap(f, pai(k));  
// }

void desceHeap(FilaPrioridade* f, int k){
    if(filhoEsquerda(k) < f->qtde){
        int maiorFilho = filhoEsquerda(k);
        int temFilhoDireita = (filhoDireita(k) < f->qtde ? 1 : 0);
        if(temFilhoDireita && f->vetor[filhoDireita(k)] > f->vetor[filhoEsquerda(k)]){
            maiorFilho = filhoDireita(k);
        }

        if(f->vetor[maiorFilho] > f->vetor[k]){
            troca(f->vetor + maiorFilho, f->vetor + k);
            desceHeap(f, maiorFilho);   
        }


    }

}