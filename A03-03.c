#include <stdio.h>

char conceitoCon1(float n1){
  if (n1>10 || n1<0){
    return 'X';
  }
  else if (n1>9.0 || n1==9.0)
    return 'A';
  else if (n1>7.0)
    return 'B';
  else if (n1>6.0)
    return 'C';
  else
    return 'I';
}

char conceitoCon2(float n1, char *conc){
  if (n1>10 || n1<0){
    *conc='X';
  }
  else if (n1>9.0 || n1==9.0)
    *conc= 'A';
  else if (n1>7.0)
    *conc= 'B';
  else if (n1>6.0)
    *conc= 'C';
  else
    *conc= 'I';
}

void main(){
  //teste caso 1
  printf("Conceito: %c\n", conceitoCon1(10));
  printf("Conceito: %c\n", conceitoCon1(5.5));
  printf("Conceito: %c\n", conceitoCon1(11));

  //teste caso 2
  char conceito;
  conceitoCon2(10, &conceito);
  printf("%c\n", conceito);
  conceitoCon2(5.5, &conceito);
  printf("%c\n", conceito);
  conceitoCon2(11, &conceito);
  printf("%c\n", conceito);
}
