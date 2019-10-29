#include <stdio.h>
#include "FilaCircular.h"
//#include "FilaEncadeada.h"

int main(){
    int x;
    int* xp;

    //CRIAR A FILA
    Fila* f1 = fila_criar();

    //INSERE UM ELEMENTO NA FILA
    x = fila_inserir(f1,10);
    x = fila_inserir(f1,20);
    x = fila_inserir(f1,30);
    x = fila_inserir(f1,40);
    x = fila_inserir(f1,50);
    x = fila_inserir(f1,60);

    //REMOVE O PRIMEIRO DA FILA
    xp = fila_remover1(f1);
    if (xp != NULL){
        printf("\n%d saiu da fila!\n",*xp);
    }

    x = fila_remover2(f1,xp);
    if (x != false){
        printf("\n%d saiu da fila!\n",*xp);
    }

    //PRIMEIRO DA FILA
    x = fila_primeiro(f1,xp);
    if (x != false){
        printf("\n%d primeiro da fila!\n",*xp);
    }

    //TAMANHO DA FILA
    x = fila_tamanho(f1);
    printf("\nTamanho da fila: %d\n",x);

    //FILA CONTEM UM NÚMERO
    x = fila_contem(f1,40);
    if (x != -1){
        printf("\nO numero esta na posicao: %d\n",x);
    }

    //IMPRIME A FILA
    fila_imprimir(f1);

    //DESTRUIR A FILA
    fila_destruir(f1);

    return 0;
}