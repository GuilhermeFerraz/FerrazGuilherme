#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* string_clone(char *s){
  char* str2 = (char*) calloc (20, sizeof(char));
  strcpy(str2,s);

  return str2;
}

void main(){
  char str[20] = "ABC";
  char* copia = string_clone(str);
  printf("Texto: %s\n", copia);
}
