#include <stdio.h>
#include <string.h>
#include "TAD_vetor.h"

int main(){
    int x;
    int* pnt = (DataType* )malloc(sizeof(DataType));

    // Criando o vetor
    Vetor* v1 = vetor_new();
    Vetor* v77 = vetor_new();

    // Imprindo o vetor
    vetor_print(v1);

    // Inserindo elemento em uma posição do vetor
    x = vetor_insert(v1, 30, 0);
    if (x != 0){
        vetor_print(v1);
    }
    x = vetor_insert(v1, 20, 0);
    if (x != 0){
        vetor_print(v1);
    }
    x = vetor_insert(v1, 10, 0);
    if (x != 0){
        vetor_print(v1);
    }

    // Inserindo elemento no final do vetor
    x = vetor_add(v1, 40);
    if (x != 0){
        vetor_print(v1);
    }
    x = vetor_add(v1, 50);
    if (x != 0){
        vetor_print(v1);
    }
    x = vetor_add(v1, 60);
    if (x != 0){
        vetor_print(v1);
    }
    x = vetor_add(v1, 70);
    if (x != 0){
        vetor_print(v1);
    }
    x = vetor_add(v1, 80);
    if (x != 0){
        vetor_print(v1);
    }

    x = vetor_add(v77, 1);
    x = vetor_add(v77, 2);
    x = vetor_add(v77, 3);
    x = vetor_add(v77, 4);
    x = vetor_add(v77, 5);
    vetor_print(v77);

    // Criar um sub-vetor com base nos elementos
    Vetor* v22 = vetor_filter(v77, &ehPar);
    vetor_print(v22); // [2,4]
    Vetor* v33 = vetor_filter(v77, &ehImpar);
    vetor_print(v33); // [1,3,5]

    // Remover um elemento do vetor de uma posição específica
    x = vetor_remove1(v1, 5);
    printf("\n'%d' removido do vetor!\n", x);
    x = vetor_remove1(v1, 3);
    printf("\n'%d' removido do vetor!\n", x);
    vetor_print(v1);

    x = vetor_remove2(v1, 0, pnt);
    if (x != 0){
        printf("\nValor removido: %d\n", *pnt);
    }

    // Remover o elemento da primeira posição do vetor
    x = vetor_shift1(v1);
    printf("\n'%d' foi removido do vetor!\n", x);
    vetor_print(v1);

    x = vetor_shift2(v1, pnt);
    if (x != 0){
        printf("\nValor que foi removido: %d\n", *pnt);
    }

    // Acessar um elemento do vetor
    x = vetor_get1(v1, 0);
    printf("\nValor acessado: %d\n", x);

    x = vetor_get2(v1, 1, pnt);
    if (x != 0){
        printf("\nValor que foi acessado: %d\n", *pnt);
    }

    pnt = vetor_get3(v1, 0);
    printf("\nValor acessado agora: %d\n", *pnt);

    // Alterar um elemento no vetor
    x = vetor_set(v1, 0, 100);
    if (x != 0){
        vetor_print(v1);
    }

    // Aplicar uma alteração à todos os elementos do vetor
    vetor_map(v1, vetor_set);
    vetor_print(v1);

    // Criar um sub‒vetor
    Vetor* v1sb = vetor_sub1(v1, 1);
    vetor_print(v1sb);
    v1sb = vetor_sub1(v1, -1);
    vetor_print(v1sb);
    
    v1sb = vetor_sub2(v1, 0, 1);
    vetor_print(v1sb);

    // Acessar o tamanho do vetor
    x = vetor_size(v1);
    printf("\nTamanho do vetor: %d\n", x);

    // Importar
    x = vetor_import(v1, "vetimporta.txt");
    vetor_print(v1);

    // Salvar o estado da memória
    x = vetor_save(v1, "save.bin");
    printf("\nBytes armazenados: %d\n", x);

    // Carregar o estado da memória
    v1 = vetor_load("save.bin");
    vetor_print(v1);

    // Limpando o vetor
    vetor_free(v1);
    vetor_free(v77);
    
    return 0;
}
