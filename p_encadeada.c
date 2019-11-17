#include <stdio.h>
#include "Pilha_encadeada.h"

int main(){
    Tipo x;
    Tipo* y;
    Tipo vet1[3] = {100,200,300};
    Tipo* vetpont = vet1;

    //CRIA A PILHA
    Pilha* p1 = pilha_criar();

    //INSERIR ELEMENTO
    x = pilha_push(p1, 10);
    x = pilha_push(p1, 20);
    x = pilha_push(p1, 30);
    x = pilha_push(p1, 40);
    x = pilha_push(p1, 50);
    pilha_imprimir(p1);

    //REMOVE O TOPO
    y = pilha_pop1(p1);
    printf("\n%d Removido!\n", *y);

    x = pilha_pop2(p1,y);
    printf("\n%d Removido!\n", *y);

    //PROCURA ELEMENTO
    x = pilha_posicao(p1,20);
    if (x != -1){
        printf("\nElemento esta na posicao '%d'\n", x);
    }
    else{
        printf("\nElemento nao encontrado\n");
    }

    //TAMANHO DA PILHA
    x = pilha_tamanho(p1);
    printf("\nElementos na pilha: %d\n", x);
    pilha_imprimir(p1);

    //ADICIONA VETOR NA PILHA
    x = pilha_pushAll(p1,vetpont,3);
    printf("\n%d elementos adicionados\n", x);
    pilha_imprimir(p1);

    //INVERTE A PILHA
    pilha_inverter(p1);
    pilha_imprimir(p1);

    //CLONE DA PILHA
    Pilha* v1clone = pilha_clone(p1);
    pilha_imprimir(v1clone);

    //DESALOCA NÓ
    pilha_destruir(p1);


    return 0;
}