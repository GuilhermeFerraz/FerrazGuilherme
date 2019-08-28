#include <stdio.h>
#include <stdlib.h>

int vetor_novoA(int t, int p){
  int *v = (int*) calloc (t, sizeof(int));
  for(int i = 0; i < t; i++){
    v[i] = p;
  }
  return v;
}

void vetor_novoB(int t, int p, int *vet){
  int *vb = (int*) calloc (t, sizeof(int));
  for(int i = 0; i < t; i++){
    vb[i] = p;
  }
  *vet=vb;
}

void main(){
  int *v1;
  v1 = vetor_novoA(10, -1);
  for(int i = 0; i < 10; i++){
    printf("%d\t", v1[i]);
  }
  printf("\n");
  v1 = vetor_novoA(5, 2);
  for(int i = 0; i < 5; i++){
    printf("%d\t", v1[i]);
  }
  printf("\n");
  printf("\n");

  int *v2;
  vetor_novoB(6, 0, &v2);
  for(int i = 0; i < 6; i++){
    printf("%d\t", v2[i]);
  }
  printf("\n");
  vetor_novoB(15, -5, &v2);
  for(int i = 0; i < 15; i++){
    printf("%d\t", v2[i]);
  }
}
