
#include <stdio.h>
#include <stdlib.h>


typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int inicio;
    int fim;
}Fila;


Fila* fila_criar(); //DONE
void fila_destruir(Fila* f); //DONE

Boolean fila_inserir(Fila* f, Tipo elemento); //DONE
Tipo* fila_duplica(Fila* f); //DONE
Tipo* fila_remover1(Fila* f); //DONE
Boolean fila_remover2(Fila* f, Tipo* endereco); //DONE

Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f); //DONE
int fila_contem(Fila* f, Tipo elemento); //DONE
void fila_imprimir(Fila* f); //DONE


//IMPLEMENTOS
Fila* fila_criar(){
    Fila* nova = (Fila*)malloc(sizeof(Fila));
    nova->vetor = (Tipo*)calloc(6,sizeof(Tipo));
    nova->tam = 6;
    nova->inicio = 0;
    nova->fim = 0;
    return nova;
}

void fila_destruir(Fila* f){
    free(f->vetor);
    free(f);
}

Boolean fila_inserir(Fila* f, Tipo elemento){
    if ((f->fim + 1) == f->inicio || ((f->fim + 1 ) % f->tam) == f->inicio){
        f->vetor = fila_duplica(f);
    }
    int comp=0;
    for (int i = f->inicio%f->tam; (i%(f->tam+1)) != f->fim%f->tam; i++){
        if (elemento < f->vetor[i%(f->tam+1)]){
            comp = (i-1%(f->tam+1));
            for (int j=f->fim%f->tam; j!=comp; j--){
                f->vetor[j+1%(f->tam+1)] = f->vetor[j%(f->tam+1)];
            }
            f->vetor[comp] = elemento;
        }
    }
    return true;
}

Tipo* fila_duplica(Fila* f){
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

Tipo* fila_remover1(Fila* f){
    Tipo* xp = (Tipo*)malloc(sizeof(Tipo));
    if(f->inicio%f->tam == f->fim%f->tam){
        return NULL;
    }
    *xp = f->vetor[f->inicio%f->tam];
    f->inicio++;
    return xp;
}

Boolean fila_remover2(Fila* f, Tipo* endereco){
    if(f->inicio%f->tam == f->fim%f->tam){
        return false;
    }
    *endereco = f->vetor[f->inicio%f->tam];
    f->inicio++;
    return true;
}

Boolean fila_primeiro(Fila* f, Tipo* endereco){
    if(f->inicio%f->tam == f->fim%f->tam){
        return false;
    }
    *endereco = f->vetor[f->inicio%f->tam];
    return true;
}

int fila_tamanho(Fila* f){
    Tipo cont=0;
    for (int i = f->inicio%f->tam; (i%(f->tam+1)) != f->fim%f->tam; i++){
        cont++;
    }
    return cont;
}

void fila_imprimir(Fila* f){
    printf("\n");
    for (int i = f->inicio%f->tam; (i%(f->tam+1)) != f->fim%f->tam; i++){
        printf("%d   ",f->vetor[i%(f->tam+1)]);
    }
}

int fila_contem(Fila* f, Tipo elemento){
    for (int i = f->inicio%f->tam; (i%(f->tam+1)) != f->fim%f->tam; i++){
        if (f->vetor[i%(f->tam+1)] == elemento){
            return i%(f->tam);
        }
    }
    return -1;
}