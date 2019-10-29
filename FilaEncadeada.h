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
 * Estrutura usada para representar e armazenar a FILA com alocação encadeada.
 */
typedef struct{
    No* prim;
    No* ult;
    int qtde;
}Fila;


Fila* fila_criar(); //DONE
void fila_destruir(Fila* f); //DONE
void desalocaNo(No* no); //DONE

Boolean fila_inserir(Fila* f, Tipo elemento); //DONE
Tipo* fila_remover1(Fila* f); //DONE
Boolean fila_remover2(Fila* f, Tipo* endereco); //DONE

Boolean fila_primeiro(Fila* f, Tipo* endereco); //DONE
int fila_tamanho(Fila* f); //DONE
int fila_contem(Fila* f, Tipo elemento); //DONE
void fila_imprimir(Fila* f); //DONE

Fila* fila_criar(){
    Fila* nova = (Fila*)malloc(sizeof(Fila));
    nova->prim = NULL;
    nova->ult = NULL;
    nova->qtde = 0;
    return nova;
}

void fila_destruir(Fila* f){
    if(f == NULL) return;
    free(f->ult);
    desalocaNo(f->prim);
    free(f);
}

void desalocaNo(No* no){
    if(no == NULL) return;
    desalocaNo(no->prox);
    free(no);
}

Boolean fila_inserir(Fila* f, Tipo elemento){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = elemento;
    novo->prox = NULL;
    if (f->qtde == 0){
        f->prim = novo;
        f->ult = novo;
        f->qtde++;
        return true;
    }
    No* aux;
    aux = f->prim;
    while (aux != NULL){
        if (aux->prox == NULL){
            aux->prox == novo;
            f->ult = novo;
            f->qtde++;
            return true;
        }
        aux = aux->prox;
    }
}

Tipo* fila_remover1(Fila* f){
    if (f->qtde == 0) return NULL;

    Tipo* xp;
    No* aux;
    aux = f->prim;
    f->prim = f->prim->prox;
    f->qtde--;
    *xp = aux->dado;
    free(aux);
    return xp;
}

Boolean fila_remover2(Fila* f, Tipo* endereco){
    if (f->qtde == 0) return false;

    No* aux;
    aux = f->prim;
    f->prim = f->prim->prox;
    f->qtde--;
    *endereco = aux->dado;
    free(aux);
    return true;
}

Boolean fila_primeiro(Fila* f, Tipo* endereco){
    if (f->qtde == 0) return false;

    *endereco = f->prim->dado;
    return true;
}

int fila_tamanho(Fila* f){
    return f->qtde;
}

int fila_contem(Fila* f, Tipo elemento){
    int cont=0;
    No* aux;
    aux = f->prim;
    while (aux != NULL){
        if(aux->dado == elemento){
            return cont;
        }
        cont++;
        aux = aux->prox;
    }
    return -1;
}

void fila_imprimir(Fila* f){
    printf("\n");
    No* aux;
    aux = f->prim;
    while (aux != NULL){
        printf("%d   ",aux->dado);
        aux = aux->prox;
    }
}