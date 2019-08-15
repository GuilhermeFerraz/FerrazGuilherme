#include <stdio.h>

char conceitoCon(float n1){
  if (n1>9.0 || n1==9.0)
    return 'A';
  else if (n1>7.0)
    return 'B';
  else if (n1>6.0)
    return 'C';
  else
    return 'I';
}

void main(){
  float nota = 10.0;
  char conceito;
  conceito=conceitoCon(nota);
  printf("Conceito: %c\n", conceito);
}
