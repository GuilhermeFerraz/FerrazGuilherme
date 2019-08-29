#include <stdio.h>
#include <stdlib.h>

int vetor_incrementa(int *v,int t){
  for (int i=0;i<t;i++){
    v[i]++;
  }
}

int main(){
  int v1[5] = {10,20,30,40,50};
  vetor_incrementa(v1, 5);
  for (int i=0;i<5;i++){
    printf("%d\t",v1[i]);
  }
}
