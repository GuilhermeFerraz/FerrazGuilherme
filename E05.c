#include <stdio.h>
#include <math.h>

void saqueDinheiro(int x, int *v1){
  int res;
  v1[0]=floor(x/100);
  res=(x%100);
  v1[1]=floor(res/50);
  x=(res%50);
  v1[2]=floor(x/20);
  res=(x%20);
  v1[3]=floor(res/10);
  x=(res%10);
  v1[4]=floor(x/5);
  res=(x%5);
  v1[5]=floor(res/2);
  x=(res%2);
}

void main(){
  int dinheiro=275, v[6];
  saqueDinheiro(dinheiro, &v);

  for (int i=0; i<6; i++){
    if (v[i]!=0){
      if (i==0)
      printf("%d notas de 100\n", v[i]);
      if (i==1)
      printf("%d notas de 50\n", v[i]);
      if (i==2)
      printf("%d notas de 20\n", v[i]);
      if (i==3)
      printf("%d notas de 10\n", v[i]);
      if (i==4)
      printf("%d notas de 5\n", v[i]);
      if (i==5)
      printf("%d notas de 2\n", v[i]);
    }
  }
}
