#include <stdio.h>
#include <string.h>

char verificaInstancia(char* a);

char verificaInstancia(char* a){
    char resultado;
    char pilha[100001];
    int cont = -1;

    for (int i=0; i<=strlen(a); i++){

        if (a[i] == '{' || a[i] == '[' || a[i] == '('){
            pilha[cont+1] = a[i];
            cont++;
        }

        if (a[i] == '}' || a[i] == ']' || a[i] == ')'){
            if(a[i] == '}'){
                if(pilha[cont] != '{'){
                    resultado = 'N';
                    return resultado;
                }
            }
            if(a[i] == ']'){
                if(pilha[cont] != '['){
                    resultado = 'N';
                    return resultado;
                }
            }
            if(a[i] == ')'){
                if(pilha[cont] != '('){
                    resultado = 'N';
                    return resultado;
                }
            }
            cont--;
        }

    }

    if (pilha[cont]=='(' || pilha[cont]=='{' || pilha[cont]=='['){
        resultado = 'N';
        return resultado;
    }

    resultado = 'S';
    return resultado;
}


int main(){
    int t;
    char a[100001], resultado;
    
    scanf("%d",&t);
       
    for(int i=0;i<t;i++){
        
        scanf("%s",a);
        resultado = verificaInstancia(a);
        printf("%c\n",resultado);
    }

}