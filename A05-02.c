#include <stdio.h>
#include <stdlib.h>

int* vetor_aleatorio(int t){
  int *vet= (int*) calloc (t, sizeof(int));
  for (int i = 0; i < t; i++){
    vet[i] = rand()%100;
  }
  return vet;
}

void main(){
  int *v1 = vetor_aleatorio(10);
  for (int i = 0; i < 10; i++){
    printf("%d\t",v1[i]);
  }
  printf("\n");
  int *v2 = vetor_aleatorio(100);
  for (int i = 0; i < 100; i++){
    printf("%d\t",v2[i]);
  }
}
