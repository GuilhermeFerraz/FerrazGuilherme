#include <stdio.h>
#include <stdlib.h>
#include "Lista_Sentinela.h"

int main(){
    int x;
    int* y;
    
    //CRIA LISTA
    Lista* l = lista_criar();

    //INSERE
    lista_inserir(l,20,0);
    lista_inserir(l,10,5);
    lista_inserir(l,10,0);
    lista_inserir(l,40,2);
    lista_inserir(l,30,2);

    lista_inserir_fim(l,50);
    lista_inserir_fim(l,60);

    lista_imprimir(l);

    //REMOVE
    y = lista_remover1(l, 0);
    y = lista_remover1(l, l->qtde-1);

    x = lista_remover2(l, 2, y);
    lista_imprimir(l);

    x = lista_remover_elemento(l,30);
    lista_imprimir(l);

    //BUSCAR
    x = lista_buscar(l,0,y);
    if (x != false) printf("\nElemento buscado: %d\n", *y);
    else printf("\nPosicao passada e invalida!\n");

    //CONTÉM
    x = lista_contem(l,50);
    if (x != false) printf("\nO elemento esta presente na lista!\n");
    else printf("\nElemento nao encontrado!\n");

    //POSIÇÃO
    x = lista_posicao(l, 50);
    if (x != -1) printf("\nO elemento esta na posicao: %d\n", x);
    else printf("\nElemento nao encontrado na lista!\n");

    //TAMANHO
    x = lista_tamanho(l);
    printf("\nTamanho da lista: %d\n", x);

    //IMPRIMIR
    lista_imprimir(l);

    //DESTOIA LISTA
    lista_destruir(l);

return 0;
}