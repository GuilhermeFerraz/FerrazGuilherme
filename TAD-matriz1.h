#include <stdio.h>
#include <stdlib.h>


// DADOS
typedef struct{
    int **m;
    int linhas;
    int colunas;
} Matriz;


//OPERAÇÕES (PROTÓTIPOS)
Matriz *matriz_cria(int linhas, int colunas);
void matriz_atribui(Matriz *m, int lin, int col, int valor);
int matriz_acessa1(Matriz *m, int lin, int col);
void matriz_acessa2(Matriz *m, int lin, int col, int *end);
void matriz_imprime(Matriz *m);
int matriz_linhas(Matriz* m);
int matriz_colunas(Matriz* m);
void matriz_map1(Matriz* m, void (*funcao)(int*));
void matriz_map2(Matriz* m, int (*funcao)(int));
Matriz* matriz_multiplica(Matriz* a, Matriz* b);
int matriz_ehQuadrada(Matriz* m);
int matriz_ehDiagonal(Matriz* m);
int matriz_ehIdentidade(Matriz* m);
Matriz* matriz_transposta(Matriz* m);
Matriz* matriz_oposta(Matriz* m);
void matriz_destroi(Matriz *m);


//OPERAÇÕES (IMPLEMENTAÇÃO)
Matriz *matriz_cria(int linhas, int colunas){
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    mat->m = (int **)calloc(linhas, sizeof(int *));
    int i;
    for (i = 0; i < linhas; i++)
    {
        mat->m[i] = (int *)calloc(colunas, sizeof(int));
    }
    mat->linhas = linhas;
    (*mat).colunas = colunas;

    return mat;
}

void matriz_atribui(Matriz *m, int lin, int col, int valor){
  m->m[lin][col] = valor;
}

int matriz_acessa1(Matriz *m, int lin, int col){
  return (m->m[lin][col]);
}

void matriz_acessa2(Matriz *m, int lin, int col, int *end){
  *end = (m->m[lin][col]);

}

void matriz_imprime(Matriz *m){
  int linha=(m->linhas);
  int coluna=(m->colunas);
  printf("-------------------------------\n");
  for (int i=0; i<linha; i++){
    for (int y=0; y<coluna; y++){
      printf("%d\t",m->m[i][y]);
    }
    printf("\n");
  }
  printf("-------------------------------\n");
}

int matriz_linhas(Matriz* m){
  return m->linhas;
}

int matriz_colunas(Matriz* m){
  return m->colunas;
}

Matriz* matriz_multiplica(Matriz* a, Matriz* b){
  int multi;
  
  Matriz *prodNull = matriz_cria(a->linhas, b->colunas);
  for (int i=0; i<a->linhas; i++){
    for (int j=0; j<b->colunas; j++){
      prodNull->m[i][j] = 0;
    }
  }

  Matriz *prod = matriz_cria(a->linhas, b->colunas);
  if (a->colunas == b->linhas){
    for (int i=0; i < a->linhas; i++){
      for (int j=0; j < b->colunas; j++){
        multi=0;
        for (int x=0; x < a->colunas; x++){
          multi=(multi+((a->m[i][x])*(b->m[x][j])));
        }
        prod->m[i][j]=multi;
      }
    }
    prod->linhas = a->linhas;
    prod->colunas = b->colunas;
    return prod;
  }
  return prodNull;
}

void matriz_destroi(Matriz *m){
  for (int i=0;i<m->linhas;i++){
    free(m->m[i]);
  }
  free(m->m);
  free(m);
}

int matriz_ehQuadrada(Matriz* m){
  if (m->colunas == m->linhas){
    return 1;
  }
  else{
    return 0;
  }
}

int matriz_ehDiagonal(Matriz* m){
  int x = matriz_ehQuadrada(m);
  if (x==1){
    for (int i=0;i<m->linhas;i++){
      for (int j=0;j<m->colunas;j++){
        if (m->m[i][j]!=0 && i!=j )
        return 0;
      }
    }
    return 1;
  }
  else
  return 0;
}

int matriz_ehIdentidade(Matriz* m){
  int q = matriz_ehQuadrada(m);
  if (q == 1){
    for (int i=0; i<m->linhas; i++){
      for (int j=0; j<m->colunas; j++){
        if (i==j && m->m[i][j]!=1){
          return 0;
        }
      }
    }
    for (int i=0;i<m->linhas;i++){
      for (int j=0;j<m->colunas;j++){
        if (m->m[i][j]!=0 && i!=j )
        return 0;
      }
    }
    return 1;
  }
  else
    return 0;
}

Matriz* matriz_transposta(Matriz* m){
  Matriz *tp = matriz_cria(m->colunas, m->linhas);
  for (int i=0; i<m->linhas; i++){
    for (int j=0; j<m->colunas; j++){
      tp->m[j][i] = m->m[i][j];
    }
  }
  return tp;
}

Matriz* matriz_oposta(Matriz* m){
  Matriz *op = matriz_cria(m->linhas, m->colunas);
  for (int i=0; i<m->linhas; i++){
    for (int j=0; j<m->colunas; j++){
      op->m[i][j] = (m->m[i][j] * -1);
    }
  }
  return op;
}

int* matriz_vetorLinha(Matriz* m, int linha){
  int* vet = (int*)calloc(m->colunas + 1, sizeof(int));
  vet[m->colunas + 1] = m->colunas;
  for (int i=0; i<m->colunas; i++){
    vet[i] = m->m[linha - 1][i];
  }
  return vet;
}

int* matriz_vetorColuna(Matriz* m, int coluna){
  int* vetcol = (int*)calloc(m->linhas +1, sizeof(int));
  vetcol[m->linhas + 1] = m->linhas;
  for (int i=0; i<m->linhas; i++){
    vetcol[i] = m->m[i][coluna -1];
  }
  return vetcol;
}

void matriz_map1(Matriz* m, void (*funcao)(int*)){
  
}

void matriz_map2(Matriz* m, int (*funcao)(int)){

}