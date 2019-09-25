#include <stdio.h>

#include "TAD-matriz1.h"
//#include "TAD-matriz2.h"

int main()
{

    // criar matriz
    Matriz *m1 = matriz_cria(2, 3);
    Matriz *m4 = matriz_cria(3, 4);

    // atribui valores nas celulas
    matriz_atribui(m1, 0, 1, 10);
    matriz_atribui(m4, 0, 1, 5);

    // acessar valores das celulas
    int x1 = matriz_acessa1(m1, 0, 1);
    int x2;
    matriz_acessa2(m1, 0, 1, &x2);

    // imprimir a matriz
    matriz_imprime(m1);
    matriz_imprime(m4);

    // recupera linha
    int linharec = matriz_linhas(m1);
    printf("\nLinha(s) m1: %d\n", linharec);

    // recupera coluna
    int colunarec = matriz_colunas(m1);
    printf("\nColuna(s) m1: %d\n", colunarec);

    // multiplica matriz
    Matriz *produto = matriz_multiplica(m1, m4);
    matriz_imprime(produto);

    // ver se matriz é quadrada
    int q = matriz_ehQuadrada(m1);
    if (q==1)
      printf("Matriz é quadrada!\n");
    else
      printf("Matriz não é quadrada!\n");

    // ver se matriz é diagonal
    q = matriz_ehQuadrada(m1);
    if (q==1)
      printf("Matriz é diagonal!\n");
    else
      printf("Matriz não é diagonal!\n");

    // ver se matriz é identidade
    q = matriz_ehIdentidade(m4);
    if (q==1)
      printf("Matriz é identidade!\n");
    else
      printf("Matriz não é identidade!\n");
    
    // matriz transposta
    Matriz *m1t = matriz_transposta(m1);
    matriz_imprime(m1t);

    // matriz oposta
    Matriz *opm4 = matriz_oposta(m4);
    matriz_imprime(opm4);

    //cópia linha matriz
    int* vetLinha = matriz_vetorLinha(m1, 1);
    for (int i=0; i<sizeof(vetLinha) -1; i++){
        printf("%d\t", vetLinha[i]);
    }

    printf("\n\n");

    //cópia coluna matriz
    int* vetColuna = matriz_vetorColuna(m1, 2);
    for (int i=0; i<sizeof(vetColuna) -1; i++){
        printf("%d\t\n", vetColuna[i]);
    }

    // destruir matriz
    matriz_destroi(m1);
    matriz_destroi(m4);

}