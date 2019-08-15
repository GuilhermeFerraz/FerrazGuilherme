#include <stdio.h>
#include <string.h>

char converteDia(int d, char *d1){
  if (d==1)
  strcpy(d1, "Um");
  else if (d==2){
    strcpy(d1, "Dois");
  }
  else if (d==3){
    strcpy(d1, "Três");
  }
  else if (d==4){
    strcpy(d1, "Quatro");
  }
  else if (d==5){
    strcpy(d1, "Cinco");
  }
  else if (d==6){
    strcpy(d1, "Seis");
  }
  else if (d==7){
    strcpy(d1, "Sete");
  }
  else if (d==8){
    strcpy(d1, "Oito");
  }
  else if (d==9){
    strcpy(d1, "Novo");
  }
  else if (d==10){
    strcpy(d1, "Dez");
  }
  else if (d==11){
    strcpy(d1, "Onze");
  }
  else if (d==12){
    strcpy(d1, "Doze");
  }
  else if (d==13){
    strcpy(d1, "Treze");
  }
  else if (d==14){
    strcpy(d1, "Quatorze");
  }
  else if (d==15){
    strcpy(d1, "Quinze");
  }
  else if (d==16){
    strcpy(d1, "Dezesseis");
  }
  else if (d==17){
    strcpy(d1, "Dezessete");
  }
  else if (d==18){
    strcpy(d1, "Dezoito");
  }
  else if (d==19){
    strcpy(d1, "Dezenove");
  }
  else if (d==20){
    strcpy(d1, "Vinte");
  }
  else if (d==21){
    strcpy(d1, "Vinte e um");
  }
  else if (d==22){
    strcpy(d1, "Vinte e dois");
  }
  else if (d==23){
    strcpy(d1, "Vinte e três");
  }
  else if (d==24){
    strcpy(d1, "Vinte e quatro");
  }
  else if (d==25){
    strcpy(d1, "Vinte e cinco");
  }
  else if (d==26){
    strcpy(d1, "Vinte e seis");
  }
  else if (d==27){
    strcpy(d1, "Vinte e sete");
  }
  else if (d==28){
    strcpy(d1, "Vinte e oito");
  }
  else if (d==29){
    strcpy(d1, "Vinte e nove");
  }
  else if (d==30){
    strcpy(d1, "Trinta");
  }
  else if (d==31){
    strcpy(d1, "Trinta e um");
  }
}

char converteMes(int m, char *m1){
  if (m==1)
  strcpy(m1, " de Janeiro de ");
  else if (m==2){
    strcpy(m1, " de Fevereiro de ");
  }
  else if (m==3){
    strcpy(m1, " de Março de ");
  }
  else if (m==4){
    strcpy(m1, " de Abril de ");
  }
  else if (m==5){
    strcpy(m1, " de Maio de ");
  }
  else if (m==6){
    strcpy(m1, " de Junho de ");
  }
  else if (m==7){
    strcpy(m1, " de Julho de ");
  }
  else if (m==8){
    strcpy(m1, " de Agosto de ");
  }
  else if (m==9){
    strcpy(m1, " de Setembro de ");
  }
  else if (m==10){
    strcpy(m1, " de Outubro de ");
  }
  else if (m==11){
    strcpy(m1, " de Setembro de ");
  }
  else if (m==12){
    strcpy(m1, " de Dezembro de ");
  }
}

void main(){
  int dia=15, mes=8, ano=2019;
  char dia1[51], mes1[51];

  converteDia(dia, &dia1);
  converteMes(mes, &mes1);

  printf("%s%s%d\n", dia1, mes1, ano);
}
