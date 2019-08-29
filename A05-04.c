#include <stdio.h>
#include <stdlib.h>

void vetor_dobra(int *v,int t){
  for (int i=0;i<t;i++){
    v[i]=(v[i]*2);
  }
}

void main(){
  int v1[5] = {10,20,30,40,50};
  vetor_dobra(v1, 5);
  for (int i=0;i<5;i++){
    printf("%d\t",v1[i]);
  }
}
