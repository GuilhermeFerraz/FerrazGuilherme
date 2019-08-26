#include <stdio.h>

int potenciaNumero1(int x, int y){
  int resul=x;
  if (y!=0 && y>0){
    for (int i=1; i<y; i++){
      resul*=x;
    }
    return resul;
  }
  else if ( y < 0 ){
    int g=0;
    y=(y*(-1));
    while (g<y){
      resul*=(1/x);
      g++;
    }
    return resul;
  }
  else{
    return 1;
  }
}

void potenciaNumero2(int x, int y, int *resul){
  *resul=x;
  if (y!=0 && y>0){
    for (int i=1; i<y; i++){
      *resul*=x;
    }
  }
  else if ( y < 0 ){
    int g=0;
    y=(y*(-1));
    while (g<y){
      *resul*=(1/x);
      g++;
    }
  }
  else{
    *resul=1;
  }
}

void main(){
  //teste caso 1
  printf("3^6= %d\n", potenciaNumero1(3, 6));
  printf("10^3= %d\n", potenciaNumero1(10, 3));
  printf("5^0= %d\n", potenciaNumero1(5, 0));

  //teste caso 2
  int res;
  potenciaNumero2( 3, 6, &res);
  printf("3^6= %d\n", res);
  potenciaNumero2( 10, 3, &res);
  printf("10^3= %d\n", res);
  potenciaNumero2( 5, 0, &res);
  printf("5^0= %d\n", res);
}
