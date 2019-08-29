#include <stdio.h>
#include <stdlib.h>

int vetor_dobraTamanho(int *vet, int t){
  int* v1 = (int*) calloc((t*2), sizeof(int));
  for (int i=0;i<t;i++){
    v1[i]=vet[i];
  }
  for (int i=t;i<t*2;i++){
    v1[i]=0;
  }
  free(*vet);
  for (int i=0;i<t*2;i++){
    vet[i]=v1[i];
  }
  return t*2;
}

void main(){
  int *v = (int*) calloc(4, sizeof(int));
  v[0] = 2;
  v[1] = 3;
  v[2] = 4;
  v[3] = 5;
  int novoTamanho = vetor_dobraTamanho(v,4);
  for (int i=0;i<novoTamanho;i++){
    printf("%d\t",v[i]);
  }
}
