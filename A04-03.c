#include <stdio.h>

int maiorVet(int *vet, int t){
  int maior=vet[0];
  int pos=0;
  for (int i=0; i<t; i++){
    if (maior<vet[i]){
      maior=vet[i];
      pos=i;
    }
  }
  return pos;
}

void main(){
  int v[6]={1,99,2,3,5,88};
  int c[4]={8,3,9,6};
  int z[3]={9,11,5};
  int h[5]={1,2,5,3,4};

  printf("Posição maior número: %d\n", maiorVet(v, 6)+1);
  printf("Posição maior número: %d\n", maiorVet(c, 4)+1);
  printf("Posição maior número: %d\n", maiorVet(z, 3)+1);
  printf("Posição maior número: %d\n", maiorVet(h, 5)+1);
}
