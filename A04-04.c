#include <stdio.h>
#include <stdlib.h>

int intercala_a(int *vet1, int t1, int *vet2, int t2){
  int g=0;
  int *v= (int*) calloc ((t1+t2), sizeof(int));
  int i=0;
  while (g<t1){
    v[i]=vet1[g];
    g++;
    i+=2;
  }
  g=0;
  i=1;
  while (g<t2){
    v[i]=vet2[g];
    g++;
    i+=2;
  }
  return v;
}

void intercala_b(int *vet1, int t1, int *vet2, int t2, int *vetor){
  int g=0, i=0;
  int *vb= (int*) calloc ((t1+t2), sizeof(int));
  while (g<t1){
    vb[i]=vet1[g];
    g++;
    i+=2;
  }
  g=0;
  i=1;
  while (g<t2){
    vb[i]=vet2[g];
    g++;
    i+=2;
  }
  for (int h=0; h<(t1+t2); h++){
    vetor[h]=vb[h];
  }
}

void main(){
  int v1[3]={1,3,5};
  int v2[3]={2,4,6};
  int *v4;
  v4=intercala_a(v1, 3, v2, 3);
  for (int i=0; i<6; i++){
    printf("%d\t",v4[i]);
  }
  printf("\n");
  int v11[4]={11,33,55,77};
  int v22[4]={22,44,66,88};
  v4=intercala_a(v11, 4, v22, 4);
  for (int i=0; i<8; i++){
    printf("%d\t",v4[i]);
  }
  printf("\n");

  int v3[6];
  intercala_b(v1, 3, v2, 3, v3);
  for (int i=0; i<6; i++){
    printf("%d\t",v3[i]);
  }
  printf("\n");
  intercala_b(v11, 4, v22, 4, v3);
  for (int i=0; i<8; i++){
    printf("%d\t",v3[i]);
  }
}
