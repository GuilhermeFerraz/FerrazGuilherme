
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
    int inicio;
    int fim;
}FilaPrioridade;


/************************************************
 * PROTOTIPOS
 ***********************************************/ 
FilaPrioridade* fila_criar(int tam);
void fila_destruir(FilaPrioridade* f);
Tipo* fila_duplica(FilaPrioridade* f);

Boolean fila_inserir(FilaPrioridade* f, Tipo elemento);
Boolean fila_remover(FilaPrioridade* f, Tipo* endereco);

Boolean fila_primeiro(FilaPrioridade* f, Tipo* endereco);
int fila_tamanho(FilaPrioridade* f);
int fila_contem(FilaPrioridade* f, Tipo elemento);
void fila_imprimir(FilaPrioridade* f);


/************************************************
 * IMPLEMENTACAO
 ***********************************************/ 

FilaPrioridade* fila_criar(int tam){
    FilaPrioridade* nova = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    nova->vetor = (Tipo*)calloc(6,sizeof(Tipo));
    nova->tam = 6;
    nova->inicio = 0;
    nova->fim = 0;
    return nova;
}

Boolean fila_inserir(FilaPrioridade* f, Tipo elemento){
    if ((f->fim + 1) == f->inicio || ((f->fim + 1 ) % f->tam) == f->inicio){
        f->vetor = fila_duplica(f);
    }
    for (int i = f->inicio%f->tam; (i%(f->tam+1)) != f->fim%f->tam; i++){
        if (elemento>f->vetor[i]){
            for (int j = f->fim%f->tam; (j%(f->tam+1)) != i; j--){
                f->vetor[j-1]=f->vetor[j];
            }
            f->vetor[i] = elemento;
        }
    }
    f->fim++;

    return true;
}

Tipo* fila_duplica(FilaPrioridade* f){
    int x=0;
    Tipo* vetor2 = (Tipo*)calloc(f->tam*2,sizeof(Tipo));
    for (int i=(f->inicio%f->tam); i!=(f->fim%f->tam); i++){
        if (i == f->tam){
            i = 0;
        }
        vetor2[x] = f->vetor[i];
        x++;
    }
    f->tam = f->tam*2;
    f->inicio = 0;
    f->fim = x;
    free(f->vetor);
    return vetor2;
}

Boolean fila_remover(FilaPrioridade* f, Tipo* endereco){
    Tipo* xp = (Tipo*)malloc(sizeof(Tipo));
    if(f->inicio%f->tam == f->fim%f->tam){
        return false;
    }
    *xp = f->vetor[f->inicio%f->tam];
    f->inicio++;
    return true;
}

int fila_tamanho(FilaPrioridade* f){
    Tipo cont=0;
    for (int i = f->inicio%f->tam; (i%(f->tam+1)) != f->fim%f->tam; i++){
        cont++;
    }
    return cont;
}
