#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int qtde;
}Pilha;

Pilha* pilha_criar(); //DONE
Boolean pilha_push(Pilha* p, Tipo elemento); //DONE
Tipo* pilha_pop1(Pilha* p); //DONE
Boolean pilha_pop2(Pilha* p, Tipo* end); //DONE
void pilha_destruir(Pilha* p); //DONE
void pilha_imprimir(Pilha* p); //DONE
int pilha_posicao(Pilha* p, Tipo elemento); //DONE
int pilha_tamanho(Pilha* p); //DONE
//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam); //DONE
void pilha_inverter(Pilha* p); //DONE
Pilha* pilha_clone(Pilha* p); //DONE


//IMPLEMENTAÇÕES
Pilha* pilha_criar(){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->vetor = (Tipo*)calloc(6, sizeof(Tipo));
    novo->tam = 6;
    novo->qtde = 0;
    return novo;
}

Boolean pilha_push(Pilha* p, Tipo elemento){
    if (p->qtde == p->tam) return false;

    p->qtde++;
    p->vetor[(p->qtde)-1] = elemento;
    return true;
}

void pilha_imprimir(Pilha* p){
    if (p->qtde == 0) printf("\nVetor sem elementos!\n");

    else {
        printf("Vetor:");
        for (int i=0; i<p->qtde; i++){
            printf("  %d", p->vetor[i]);
        }
        printf("\n");
    }
}

Tipo* pilha_pop1(Pilha* p){
    if(p == NULL) return NULL;
    if(p->qtde == 0) return NULL;

    Tipo* aux = (Tipo*)malloc(sizeof(Tipo));
    *aux = p->vetor[(p->qtde)-1];
    p->qtde--;
    return aux;
}

Boolean pilha_pop2(Pilha* p, Tipo* end){
    if(p == NULL) return false;
    if(p->qtde == 0) return false;

    *end = p->vetor[(p->qtde)-1];
    p->qtde--;
    return true;
}

int pilha_posicao(Pilha* p, Tipo elemento){
    for (int i=0; i<p->qtde; i++){
        if (p->vetor[i] == elemento) return i;
    }

    return -1;
}

int pilha_tamanho(Pilha* p){
    return p->qtde;
}

int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){
    if ((p->qtde + tam) > p->tam) return 0;

    for (int i=0; i<tam; i++){
        p->vetor[p->qtde+i] = vetor[i];
    }
    p->qtde += tam;
    return tam;
}

void pilha_inverter(Pilha* p){
    if (p->tam == 0) return;

    Tipo* novovet = (Tipo*)calloc(p->tam,sizeof(Tipo));
    for (int i=0; i<p->qtde; i++){
        novovet[(p->qtde -1) - i] = p->vetor[i];
    }
    free(p->vetor);
    p->vetor = novovet;
}

Pilha* pilha_clone(Pilha* p){
    Pilha* clone = pilha_criar();
    clone->qtde = p->qtde;
    for (int i=0; i<p->qtde; i++){
        clone->vetor[i] = p->vetor[i];
    }
    return clone;
}

void pilha_destruir(Pilha* p){
    free(p->vetor);
    free(p);
    printf("\nPilha destruida!\n");
}