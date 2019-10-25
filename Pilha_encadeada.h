#include <stdio.h>
#include <stdlib.h>



typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

/**
 * Registro utilizado para acomodar cada elemento da pilha (Nó).
 */
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

/**
 * Estrutura usada para representar e armazenar a PILHA com alocação encadeada.
 */
typedef struct{
    No* topo;
    int qtde;
}Pilha;

Pilha* pilha_criar(); //DONE
Boolean pilha_push(Pilha* p, Tipo elemento); //DONE
No* novoNo(Tipo elemento, No* proximo); //DONE
Tipo* pilha_pop1(Pilha* p); //DONE
Boolean pilha_pop2(Pilha* p, Tipo* end); //DONE
void pilha_destruir(Pilha* p); //DONE
void desalocaNo(No* no); //DONE
void pilha_imprimir(Pilha* p); //DONE
int pilha_posicao(Pilha* p, Tipo elemento); //DONE
int pilha_tamanho(Pilha* p); //DONE
//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam); //DONE
void pilha_inverter(Pilha* p); //DONE
Pilha* pilha_clone(Pilha* p); //DONE


//IMPLEMENTOS

Pilha* pilha_criar(){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->qtde = 0;
    novo->topo = NULL;
    return novo;
}

void pilha_destruir(Pilha* p){
    if(p == NULL) return;

    desalocaNo(p->topo);
    free(p);
}

void desalocaNo(No* no){
    if(no == NULL) return;

    desalocaNo(no->prox);
    free(no);
}

Boolean pilha_push(Pilha* p, Tipo elemento){
    No* n = novoNo(elemento, p->topo);
    p->topo = n;
    p->qtde++;
    return true;
}

No* novoNo(Tipo elemento, No* proximo){
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = elemento;
    novo->prox = proximo;
    return novo;
}

Tipo* pilha_pop1(Pilha* p){
    if (p->qtde == 0) return NULL;

    Tipo* el = (Tipo*)malloc(sizeof(Tipo));
    *el = p->topo->dado;
    No* aux = p->topo->prox;
    free(p->topo);
    p->topo = aux;
    p->qtde--;
    return el;
}

Boolean pilha_pop2(Pilha* p, Tipo* end){
    if (p->qtde == 0) return false;

    *end = p->topo->dado;
    No* aux = p->topo->prox;
    free(p->topo);
    p->topo = aux;
    p->qtde--;
    return true;
}

void pilha_imprimir(Pilha* p){
    No* aux;
    aux = p->topo;
    while (aux != NULL){
        printf("%d  ",aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int pilha_posicao(Pilha* p, Tipo elemento){
    Tipo i=0; 
    No* aux;
    aux = p->topo;
    while (aux != NULL){
        if (aux->dado == elemento) return i;
        i++;
        aux = aux->prox;
    }
    return -1;
}

int pilha_tamanho(Pilha* p){
    return p->qtde;
}

//FUNÇÕES ADICIONAIS

int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){
    for (int i=0; i<tam; i++){
        pilha_push(p,vetor[i]);
    }
    return tam;
}

void pilha_inverter(Pilha* p){
    No* novoTopo = NULL;
    No* aux;
    while(p->topo != NULL){
        aux = p->topo;
        p->topo = p->topo->prox;
        aux->prox = novoTopo;
        novoTopo = aux;
    }
    p->topo = novoTopo;
}

Pilha* pilha_clone(Pilha* p){
    int x,i=0;
    Pilha* nova = pilha_criar();
    No* aux2 = p->topo;
    while (i!=p->qtde){
        x = pilha_push(nova,aux2->dado);
        i++;
        aux2 = aux2->prox;
    }
    nova->qtde = p->qtde;
    pilha_inverter(nova);
    return nova;
}

