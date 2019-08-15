#include <stdio.h>

void potenciaNumero(int x, int y, int *resul){
  if (y!=0){
    for (int i=1; i<y; i++){
      *resul*=x;
    }
  }
  else{
    *resul=1;
  }
}

void main(){
  int numero = 2, potencia = 5, res = numero;
  potenciaNumero(numero, potencia, &res);
  printf("%d elevado a %d = %d\n", numero, potencia, res);
}
