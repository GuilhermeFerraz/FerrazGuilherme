#include <stdio.h>
#include <stdlib.h>


typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;


typedef struct no{
    Tipo dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* primeiro;
    No* ultimo;
    int qtde;
}Lista;


Lista* lista_criar(); //FEITO
void lista_destruir(Lista* l); //FEITO

void lista_inserir(Lista* l, Tipo elemento, int posicao); //FEITO
void lista_inserir_fim(Lista* l, Tipo elemento); //FEITO
No* novoNo(int elemento, No* ant, No* prox); //FEITO
No* getNo(Lista* l, int posicao); //FEITO
void insereEsq(No* ref, No* no); //FEITO

int* lista_remover1(Lista* l, int posicao); //FEITO
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco); //FEITO
Boolean lista_remover_elemento(Lista* l, Tipo elemento); //FEITO


Boolean lista_buscar(Lista* l, int posicao, int* endereco); //FEITO
Boolean lista_contem(Lista* l, Tipo elemento); //FEITO
int lista_posicao(Lista* l, Tipo elemento); //FEITO

int lista_tamanho(Lista* l); //FEITO
void lista_imprimir(Lista* l); //FEITO


Lista* lista_criar(){
    Lista* nova = (Lista*)malloc(sizeof(Lista));
    nova->primeiro = NULL;
    nova->ultimo = NULL;
    nova->qtde = 0;
    return nova;
}

void lista_destruir(Lista* l){
    if (l->qtde == 0) return;
    No* aux = l->ultimo;
    No* aux2 = aux->ant;
    for (int i=0; i<l->qtde; i++){
        free(aux);
        if (aux2->ant == NULL) break;
        else {
            aux=aux2;
            aux2=aux2->ant;
        }
    }
    free(l);
}

void lista_inserir(Lista* l, Tipo elemento, int posicao){
    if (posicao > l->qtde || posicao < 0) return;
    No* no = novoNo(elemento, NULL, NULL);
    if (l->qtde == 0){
        l->ultimo = no;
        l->primeiro = l->ultimo;
        l->qtde++;
    }
    else if (posicao == 0 && l->qtde>0){
        no->prox = l->primeiro;
        l->primeiro->ant=no;
        l->primeiro=no;
        l->qtde++;
    }
    else if (posicao == l->qtde && l->qtde>0){
        no->ant=l->ultimo;
        l->ultimo->prox=no;
        l->ultimo=no;
        l->qtde++;
    }
    else{
        No* aux = getNo(l,posicao);
        insereEsq(aux, no);
        l->qtde++;
    }
}

No* novoNo(int elemento, No* esq, No* dir){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = elemento;
    novo->ant = esq;
    novo->prox = dir;
    return novo;
}

No* getNo(Lista* l, int posicao){
    No* aux = l->primeiro;
    for(int i=0; i<posicao; i++){
        aux = aux->prox;
    }
    return aux;
}

void insereEsq (No* ref, No* no){
    no->prox=ref;
    no->ant = ref->ant;
    ref->ant->prox=no;
    ref->ant=no;
}

void lista_inserir_fim(Lista* l, Tipo elemento){
    No* no = novoNo(elemento, l->ultimo, NULL);
    l->ultimo->prox = no;
    l->ultimo = no;
    l->qtde++;
}

int lista_tamanho(Lista* l){
    return l->qtde;
}

void lista_imprimir(Lista* l){
    printf("\n");
    No* aux = l->primeiro;
    for (int i=0; i<l->qtde; i++){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int* lista_remover1(Lista* l, int posicao){
    if (posicao > l->qtde-1 || posicao < 0 || l->qtde == 0) return NULL;

    int* x = (int*)malloc(sizeof(int));
    No* aux;
    if (posicao == 0 && l->qtde>0){
        aux = l->primeiro;
        l->primeiro = aux->prox;
        aux->prox->ant = NULL;
        l->qtde--;
        *x = aux->dado;
        free (aux);
        return x;
    }
    else if (posicao == l->qtde-1 && l->qtde>0){
        aux = l->ultimo;
        l->ultimo = aux->ant;
        aux->ant->prox = NULL;
        l->qtde--;
        *x = aux->dado;
        free (aux);
        return x;
    }
    else{
        aux = getNo(l,posicao);
        *x = aux->dado;
        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        free(aux);
        l->qtde--;
        return x;
    }
}

Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco){
    if (posicao > l->qtde-1 || posicao < 0 || l->qtde == 0) return false;

    No* aux;
    if (posicao == 0 && l->qtde>0){
        aux = l->primeiro;
        l->primeiro = aux->prox;
        aux->prox->ant = NULL;
        l->qtde--;
        *endereco = aux->dado;
        free (aux);
        return true;
    }
    else if (posicao == l->qtde-1 && l->qtde>0){
        aux = l->ultimo;
        l->ultimo = aux->ant;
        aux->ant->prox = NULL;
        l->qtde--;
        *endereco = aux->dado;
        free (aux);
        return true;
    }
    else{
        aux = getNo(l,posicao);
        *endereco = aux->dado;
        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        free(aux);
        l->qtde--;
        return true;
    }
}

Boolean lista_remover_elemento(Lista* l, Tipo elemento){
    int cont = 0;
    int* x;
    No* aux = l->primeiro;
    for (int i=0; i<l->qtde; i++){
        if (aux->dado == elemento){
            x = lista_remover1(l,i);
            cont++;
        }
        aux = aux->prox;
    }
    if (cont > 0) return true;
    else return false;
}

Boolean lista_buscar(Lista* l, int posicao, int* endereco){
    if (posicao > l->qtde-1 || posicao < 0 || l->qtde == 0) return false;

    No* aux = l->primeiro;
    for (int i=0;i!=posicao;i++){
        aux = aux->prox;
    }

    *endereco = aux->dado;
    return true;
}

Boolean lista_contem(Lista* l, Tipo elemento){
    if (l->qtde == 0) return false;
    No* aux = l->primeiro;
    for (int i=0; i<l->qtde; i++){
        if (aux->dado == elemento) return true;
        else aux = aux->prox;
    }
    return false;
}

int lista_posicao(Lista* l, Tipo elemento){
    if (l->qtde == 0) return -1;
    No* aux = l->primeiro;
    for (int i=0; i<l->qtde; i++){
        if (aux->dado == elemento) return i;
        else aux = aux->prox;
    }
    return -1;
}