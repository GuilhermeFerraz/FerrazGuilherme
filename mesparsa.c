#include <stdio.h>
#include "funcoes.h"

int main(){
    int x;

    //CRIAR MATRIZ
    Matriz* m1 = matriz_criar(4, 4); 

    //INSERE
    x = matriz_atribuir(m1,0, 3, 2); //Insere normal
    if (x != false) printf("%d Adcionado na Matriz!\n", x);
    x = matriz_atribuir(m1,0, 7, 5); //NÃO IRÁ INSERIR
    if (x != false) printf("%d Adcionado na Matriz!\n", x);
    x = matriz_atribuir(m1, 1, 2, 10); //Insere normal
    if (x != false) printf("%d Adcionado na Matriz!\n", x);
    x = matriz_atribuir(m1, 1, 2, 5); //INSERE POR CIMA DE UM VALOR EXISTENTE
    if (x != false) printf("%d Adcionado na Matriz!\n", x);
    x = matriz_atribuir(m1, 1, 1, 10); //Insere por cima
    if (x != false) printf("%d Adcionado na Matriz!\n", x);
    x = matriz_atribuir(m1, 3, 0, 9); //Insere normal
    if (x != false) printf("%d Adcionado na Matriz!\n", x);
    x = matriz_atribuir(m1, 3, 3, 3); //Insere normal
    if (x != false) printf("%d Adcionado na Matriz!\n", x);

    //BUSCA NA MATRIZ
    printf("\n");
    x = matriz_acessar(m1, 3, 0); //Deve retornar '9'
    if (x != false) printf("Numero encontrado: %d\n", x);
    x = matriz_acessar(m1, 3, 7); //Não deve retornar valor
    if (x != false) printf("Numero encontrado: %d\n", x);
    x = matriz_acessar(m1, 0, 1); //Deve retornar '0'
    if (x != false) printf("Numero encontrado: %d\n", x);

    //IMPRIME MATRIZ
    matriz_imprimir(m1);

    //DESALOCAR MATRIZ
    matriz_desalocar(m1);

    return 0;
}