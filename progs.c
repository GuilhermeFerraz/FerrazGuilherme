#include<stdio.h>
//#include "Pilha_contigua.h"
#include "Pilha_encadeada.h"


int main(){
    Tipo x;
    Tipo* y;
    Tipo vet1[3] = {100,200,300};
    Tipo* vetpont = vet1;

    //CRIA O VETOR-PILHA
    Pilha* v1 = pilha_criar();

    //ADICIONA UM NÚMERO NO TOPO
    x = pilha_push(v1, 10);
    if (x == true){
        printf("\nNumero adicionado!\n");
        pilha_imprimir(v1);
    }
    else{
        printf("\nErro na insercao do numero!\n");
    }

    x = pilha_push(v1, 20);
    if (x == true){
        printf("\nNumero adicionado!\n");
        pilha_imprimir(v1);
    }
    else{
        printf("\nErro na insercao do numero!\n");
    }

    x = pilha_push(v1, 30);
    if (x == true){
        printf("\nNumero adicionado!\n");
        pilha_imprimir(v1);
    }
    else{
        printf("\nErro na insercao do numero!\n");
    }

    x = pilha_push(v1, 40);
    if (x == true){
        printf("\nNumero adicionado!\n");
        pilha_imprimir(v1);
    }
    else{
        printf("\nErro na insercao do numero!\n");
    }

    //REMOVE ELEMENTO NO TOPO
    y = pilha_pop1(v1);
    if (y != NULL) printf("\n%d removido!\n", *y);
    else printf("\nNenhum numero removido!\n");
    pilha_imprimir(v1);


    x = pilha_pop2(v1, y);
    if (x == false) printf("\nNenhum numero removido!\n");
    else printf("\n%d removido!\n", *y);
    pilha_imprimir(v1);

    //ENCONTRA UM ELEMENTO NA PILHA
    x = pilha_posicao(v1,20);
    if (x != -1){
        printf("\nElemento esta na posicao '%d'\n", x);
    }
    else{
        printf("\nElemento nao encontrado\n");
    }

    //QUANTIDADE DE ELEMENTOS DA PILHA
    x = pilha_tamanho(v1);
    printf("\nElementos na pilha: %d\n", x);

    //ADICIONA ELEMENTOS DO VETOR NA PILHA
    x = pilha_pushAll(v1,vetpont,3);
    printf("\n%d elementos adicionados\n", x);
    pilha_imprimir(v1);

    //INVERTE A PILHA
    printf("\n");
    pilha_inverter(v1);
    pilha_imprimir(v1);

    //GERA UM CLONE DA PILHA
    printf("\n");
    Pilha* v1clone = pilha_clone(v1);
    pilha_imprimir(v1clone);

    //DESTRUI A PILHA
    pilha_destruir(v1);
    pilha_destruir(v1clone);

    return 0;
}