#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char* nome;
    Produto** produtos;
    int qtde; //qtde de produtos
    int tam; //tamanho do vetor
}Empresa;

typedef struct{
    char cod[6];
    char* nome;
    float* preco;
    int qtde; //qtde de produtos no estoque
    int qtdePreco; //qtde de preços
}Produto;


Produto* novoProduto(char* cod, char* desc, float preco, int qtde);
float mediaDePreco(Empresa* e);
int buscaRemoveDuplicados(Empresa* e, char* cod);


//a)
Produto* novoProduto(char* cod, char* desc, float preco, int qtde){
    Produto* novop = (Produto*) malloc( sizeof(Produto));
    novop->cod = (char*) calloc(6, sizeof(char));
    strcpy(novop->cod, cod);
    novop->nome = (char*) calloc(strlen(desc)+1, sizeof(char));
    strcpy(novop->nome, desc);
    novop->preco = (float*) calloc(1, sizeof(float));
    novop->preco[0] = preco;
    novop->qtdePreco++;
    novop->qtde = qtde;
    return novop;
}

//b)
float mediaDePreco(Empresa* e){
    int i, j;
    float media1 = 0.0;
    float media2 = 0.0;
    for (i=0; i < e->qtde; i++){
        for (j=0; j < e->produtos[i]->qtdePreco; j++){
            media1 = media1 + e->produtos[i]->preco[j];
        }
        media1 = (media1/j);
        media2 = (media2 + media1);
        media1 = 0.0;
    }
    media2 = (media2/i);
    return media2;
}

//c)
int buscaRemoveDuplicados(Empresa* e, char* cod){
    int i, j, rmv = 0;
    for (i=0; i < e->qtde; i++){
        if (strcmp(e->produtos[i]->cod, cod) == 0){
            free(e->produtos[i]);
            rmv++;
            for (j=i; j<e->qtde; j++){
                e->produtos[j] = e->produtos[j+1];
                free(e->produtos[j+1]);
            }
        }
    }
    return rmv;
}


