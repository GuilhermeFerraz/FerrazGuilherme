#include <stdio.h>
#include <stdlib.h>

int vetor_cloneA(int *vet, int t){
  int *ve= (int*) calloc (t, sizeof(int));
  for (int i=0;i<t;i++){
      ve[i]=vet[i];
  }
  return ve;
}

void vetor_cloneB(int *vet, int t,int *vc){
  int *ve2= (int*) calloc (t, sizeof(int));
  for (int i=0;i<t;i++){
      ve2[i]=vet[i];
  }
  *vc=ve2;
}

int main(){
  int v[5] = {2,4,6,8,10};
  int *copia1, *copia2;
  copia1=vetor_cloneA(v, 5);
  for (int i=0;i<5;i++){
      printf("%d\t",copia1[i]);
  }
  printf("\n");
  vetor_cloneB(v, 5, &copia2);
  for (int i=0;i<5;i++){
      printf("%d\t",copia2[i]);
  }
}
