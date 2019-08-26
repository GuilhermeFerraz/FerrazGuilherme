#include <stdio.h>

void main(){
  short int i1 = 100;
  short int i2 = 200;
  short int i3 = 300;
  short int *v2[3] = {&i1, &i2, &i3};

  printf("i1: %d\n", i1);
  printf("&i1: %d\n", &i1);

  printf("i2: %d\n", i2);
  printf("&i2: %d\n", &i2);

  printf("i3: %d\n", i3);
  printf("&i3: %d\n", &i3);

  printf("\nv2: %d, %d, %d\n", *v2, *(v2+1), *(v2+2));
}
