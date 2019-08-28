#include <stdio.h>

void imprimeVetor(int t, int *vetor){
  for (int i=0; i<t; i++){
    if (i==0){
      printf("[%d", *vetor);
    }
    else{
      printf(", %d", vetor[i]);
    }
  }
}

void main(){
    int v[5]={10,20,30,40,50};
    int g[4]={5,10,15,20};
    int y[3]={9,8,7};
    int d[2]={1,2};
    int x[1]={3};


    imprimeVetor(5, v);
    printf("]\n");
    imprimeVetor(4, g);
    printf("]\n");
    imprimeVetor(3, y);
    printf("]\n");
    imprimeVetor(2, d);
    printf("]\n");
    imprimeVetor(1, x);
    printf("]\n");
}
