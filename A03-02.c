#include <stdio.h>

int ordemInversa1(int x){
  int cont, inverso=0;
  while (x > 0){
    cont= x % 10;
    inverso= inverso * 10 + cont;
    x/= 10;
  }
  return inverso;
}

int ordemInversa2(int x, int *inverso){
  int cont;
  *inverso=0;
  while (x > 0){
    cont= x % 10;
    *inverso= *inverso * 10 + cont;
    x/= 10;
  }
}

void main(){
  //teste caso 1
  printf("Ordem inversa: %d\n", ordemInversa1(598));
  printf("Ordem inversa: %d\n", ordemInversa1(987456321));
  printf("Ordem inversa: %d\n", ordemInversa1(123456789));

  //teste caso 2
  int inv;
  ordemInversa2(598, &inv);
  printf("Inverso: %d\n", inv);
  ordemInversa2(987456321, &inv);
  printf("Inverso: %d\n", inv);
  ordemInversa2(123456789, &inv);
  printf("Inverso: %d\n", inv);
}
