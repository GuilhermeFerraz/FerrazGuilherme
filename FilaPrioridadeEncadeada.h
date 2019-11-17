
#include <stdio.h>
#include <stdlib.h>


typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

/************************************************
 * ESTRUTURA
 ***********************************************/ 
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

typedef struct{
    No* prim;
    No* ult;
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
No* novoNo(Tipo elemento);
No* procuraNoPrioridade(FilaPrioridade* f, Tipo elemento);

/************************************************
 * IMPLEMENTACAO
 ***********************************************/ 

FilaPrioridade* fila_criar(int tam){
    FilaPrioridade* fila = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    fila->prim = fila->ult = NULL;
    fila->qtde = 0;
    return fila;
}

Boolean fila_inserir(FilaPrioridade* f, Tipo elemento){
    if(f == NULL) return false;
   
    No* no = novoNo(elemento);

    if(f->prim == NULL){
        f->prim = f->ult = no;
    }else if(elemento >= f->prim->dado){
       no->prox = f->prim;
       f->prim = no;
    }else if(elemento <= f->ult->dado){
       f->ult->prox = no;
       f->ult = no;
    }else{
        No* noPosEsq = procuraNoPrioridade(f, elemento);
        no->prox = noPosEsq->prox;
        noPosEsq->prox = no;
        
        // 50 40 30 20 10

        //OUTRA OPÇÃO
        // No* anterior = f->prim;
        // No* aux = f->prim->prox;
        // while(aux != NULL){
        //     if(elemento > aux->dado){
        //         no->prox = aux;
        //         anterior->prox = no;
        //         break;
        //     }
        //     anterior = aux;
        //     aux = aux->prox;
        // }
   }

   f->qtde++;
   return true;

}

Boolean fila_remover(FilaPrioridade* f, Tipo* endereco){
    if(f->prim == NULL) return false;

    *endereco = f->prim->dado;
    No* aux = f->prim;
    f->prim = f->prim->prox;
    if(f->prim == NULL) f->ult = NULL;

    f->qtde--;
    free(aux);
    return true;
}

int fila_tamanho(FilaPrioridade* f){
    return f->qtde;
}


// FUNCOES AUXILIARES

No* novoNo(Tipo elemento){
    No* no = (No*)malloc(sizeof(No));
    no->dado = elemento;
    no->prox = NULL;
    return no;
}

No* procuraNoPrioridade(FilaPrioridade* f, Tipo elemento){
    No* aux = f->prim;
    while(aux->prox != NULL && elemento < aux->prox->dado) aux = aux->prox;

    return aux;

}