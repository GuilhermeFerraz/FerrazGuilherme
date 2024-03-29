
#include <stdio.h>
#include <stdlib.h>


typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int inicio;
    int fim;
}FilaPrioridade;


FilaPrioridade* fila_criar();
void fila_destruir(FilaPrioridade* f);

Boolean fila_inserir(FilaPrioridade* f, Tipo elemento);
Tipo* fila_duplica(FilaPrioridade* f);
Tipo* fila_remover1(FilaPrioridade* f);
Boolean fila_remover2(FilaPrioridade* f, Tipo* endereco);

Boolean fila_primeiro(FilaPrioridade* f, Tipo* endereco);
int fila_tamanho(FilaPrioridade* f);
int fila_contem(FilaPrioridade* f, Tipo elemento);
void fila_imprimir(FilaPrioridade* f);

//IMPLEMENTOS
FilaPrioridade* fila_criar(){
    FilaPrioridade* nova = (Fila*)malloc(sizeof(Fila));
    nova->vetor = (Tipo*)calloc(6,sizeof(Tipo));
    nova->tam = 6;
    nova->inicio = 0;
    nova->fim = 0;
    return nova;
}

void fila_destruir(FilaPrioridade* f){
    free(f->vetor);
    free(f);
}

Boolean fila_inserir(FilaPrioridade* f, Tipo elemento){
    if ((f->fim + 1) == f->inicio || ((f->fim + 1 ) % f->tam) == f->inicio){
        f->vetor = fila_duplica(f);
    }
    int i=f->inicio;
    while ((i%f->tam) != (f->fim%f->tam)){
        if (f->vetor[i%f->tam]<=elemento){
            for (int j = f->fim; (j%f->tam) != (i%f->tam); j++){
                f->vetor[j%f->tam] = f->vetor[(j%f->tam)-1];
            }
            f->fim++;
            break;
        }
        i++;
    }
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

Tipo* fila_remover1(FilaPrioridade* f){
    Tipo* xp = (Tipo*)malloc(sizeof(Tipo));
    if(f->inicio%f->tam == f->fim%f->tam){
        return NULL;
    }
    *xp = f->vetor[f->inicio%f->tam];
    f->inicio++;
    return xp;
}

Boolean fila_remover2(FilaPrioridade* f, Tipo* endereco){
    if(f->inicio%f->tam == f->fim%f->tam){
        return false;
    }
    *endereco = f->vetor[f->inicio%f->tam];
    f->inicio++;
    return true;
}

Boolean fila_primeiro(FilaPrioridade* f, Tipo* endereco){
    if(f->inicio%f->tam == f->fim%f->tam){
        return false;
    }
    *endereco = f->vetor[f->inicio%f->tam];
    return true;
}

int fila_tamanho(FilaPrioridade* f){
    Tipo cont=0;
    for (int i = f->inicio%f->tam; (i%(f->tam+1)) != f->fim%f->tam; i++){
        cont++;
    }
    return cont;
}

void fila_imprimir(FilaPrioridade* f){
    printf("\n");
    for (int i = f->inicio%f->tam; (i%(f->tam+1)) != f->fim%f->tam; i++){
        printf("%d   ",f->vetor[i%(f->tam+1)]);
    }
}

int fila_contem(FilaPrioridade* f, Tipo elemento){
    for (int i = f->inicio%f->tam; (i%(f->tam+1)) != f->fim%f->tam; i++){
        if (f->vetor[i%(f->tam+1)] == elemento){
            return i%(f->tam);
        }
    }
    return -1;
}