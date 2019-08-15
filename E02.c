#include <stdio.h>

int ordemInversa(int x){
  int cont, inverso=0;
  while (x > 0){
    cont= x % 10;
    inverso= inverso * 10 + cont;
    x/= 10;
  }
  return inverso;
}

void main(){
  int num = 1236468, invers0;
  invers0=ordemInversa(num);
  printf("Ordem inversa: %d\n", invers0);
}
