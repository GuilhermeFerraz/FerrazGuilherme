#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 5

typedef int DataType;
typedef enum {false, true} Boolean;

typedef struct{
    DataType* vetor;
    int size;
    int length;
} Vetor;

FILE *arq1, *arq2;

// FUNÇÕES
Vetor* vetor_new();
void vetor_free(Vetor* v);
void vetor_print(Vetor* m);
Boolean vetor_insert(Vetor* v, DataType element, int index);
DataType* vetor_duplica(Vetor* vet);
Boolean vetor_add(Vetor* v, DataType element);
DataType vetor_remove1(Vetor* v, int index);
DataType* vetor_diminui(Vetor* vet);
Boolean vetor_remove2(Vetor* v, int index, DataType* ptr);
DataType vetor_shift1(Vetor* v);
DataType vetor_get1(Vetor* v, int index);
Boolean vetor_set(Vetor* v, int index, DataType valor);
void vetor_map(Vetor* v, Boolean (*funcao)(Vetor*, int, int));
DataType vetor_size(Vetor* v);
Vetor* vetor_sub1(Vetor* v, int index);
Vetor* vetor_sub2(Vetor* v, int start, int end);
Boolean vetor_shift2(Vetor* v, DataType* ptr);
Boolean vetor_get2(Vetor* v, int index, DataType *ptr);
DataType* vetor_get3(Vetor* v, int index);
Boolean ehPar(DataType* ptr);
Boolean ehImpar(DataType* ptr);
Vetor* vetor_filter(Vetor* v, Boolean (*funcao)(DataType*));
int vetor_import(Vetor* v, char* nomeArquivo);
int vetor_save(Vetor* v, char* nomeArquivo);
Vetor* vetor_load(char* nomeArquivo);

// DESENVOLVIMENTOS
Vetor* vetor_new(){
    Vetor* v = (Vetor* )malloc(sizeof(Vetor));
    v->vetor = (int* )calloc(LENGTH, sizeof(int));
    v->size = 0;
    v->length = LENGTH;
    return v;
}

void vetor_free(Vetor* v){
    free(v->vetor);
    free(v);
}

void vetor_print(Vetor* m){
    if (m->size > 0){
        printf("\n-----------------------------------\n");
        for (int i=0; i<m->size; i++){
            printf("%d\t", m->vetor[i]);
        }
        printf("\n-----------------------------------\n");
    }
    else{
        printf("-------------------\n");
        printf("Vetor sem dados!\n");
        printf("-------------------\n");
    }
}

Boolean vetor_insert(Vetor* v, DataType element, int index){
    if (v->size == v->length){
        v->vetor = vetor_duplica(v);

    }
    if (index <= v->size){
        DataType vetcp[v->length];
        for (int i=0; i < v->size; i++){
            vetcp[i] = v->vetor[i];
        }
        for (int i=((v->length) -1); i >= 0; i--){
            if (i >= index && i <= (v->length - v->size)){
                v->vetor[i+1] = v->vetor[i];
            }
        }
        v->vetor[index] = element;
        v->size++;
        return true;
    }
    else{
        v->vetor[v->size] = element;
        v->size++;
        return true;
    }
    return false;
}

DataType* vetor_duplica(Vetor* vet){
    DataType* vetorcopia = (int* )calloc(vet->length * 2, sizeof(int));
    for (int i=0; i<vet->length; i++){
        vetorcopia[i] = vet->vetor[i];
    }
    free(vet->vetor);
    vet->length = (vet->length * 2); 
    return vetorcopia;
}

Boolean vetor_add(Vetor* v, DataType element){
    if (v->size == v->length){
        v->vetor = vetor_duplica(v);

    }
    if (v->size < v->length){
        v->vetor[v->size] = element;
        v->size++;
        return true;
    }
    return false;
}

DataType vetor_remove1(Vetor* v, int index){
    int num = v->vetor[index];
    float t;
    if (v->size <= v->length){
        if (index + 1 < v->size){
            for (int i=index; i<v->size; i++){
                v->vetor[i] = v->vetor[i+1];
            }
            v->size--;
            t = ((float)v->size /v->length);
            if (t < 0.25){
                v->vetor = vetor_diminui(v);
            }
            return num;
        }
        else{
            v->size--;
            t = ((float)v->size /v->length);
            if (t < 0.25){
                v->vetor = vetor_diminui(v);
            }
            return num;
        }
    }
    return 0;
}

DataType* vetor_diminui(Vetor* vet){
    DataType* vetorcopia = (int* )calloc(vet->length / 2, sizeof(int));
    for (int i=0; i<vet->size; i++){
        vetorcopia[i] = vet->vetor[i];
    }
    free(vet->vetor);
    vet->length = (vet->length / 2); 
    return vetorcopia;
}

Boolean vetor_remove2(Vetor* v, int index, DataType* ptr){
    *ptr = v->vetor[index];
    float t;
    if (v->size <= v->length){
        if (index + 1 < v->size){
            for (int i=index; i<v->size; i++){
                v->vetor[i] = v->vetor[i+1];
            }
            v->size--;
            t = ((float)v->size /v->length);
            if (t < 0.25){
                v->vetor = vetor_diminui(v);
            }
            return true;
        }
        else{
            v->size--;
            t = ((float)v->size /v->length);
            if (t < 0.25){
                v->vetor = vetor_diminui(v);
            }
            return true;
        }
    }
    return false;
}

DataType vetor_shift1(Vetor* v){
    int num = v->vetor[0];
    float t;
    if (v->size <= v->length){
        for (int i=0; i<v->size; i++){
            v->vetor[i] = v->vetor[i + 1];
        }
        v->size--;
        t = ((float)v->size /v->length);
            if (t < 0.25){
                v->vetor = vetor_diminui(v);
            }
        return num;
    }
    return 0;
}

DataType vetor_get1(Vetor* v, int index){
    if (index > v->size -1){
        return v->vetor[v->size -1];
    }
    else if (index <= v->size -1){
        return v->vetor[index];
    }
}

Boolean vetor_set(Vetor* v, int index, DataType valor){
    if (index <= v->size -1){
        v->vetor[index] = valor;
        return true;
    }
    else {
        return false;
    }
}

void vetor_map(Vetor* v, Boolean (*funcao)(Vetor*, int, int)){
    int j;
    for (int i=0; i<v->size; i++){
        j = funcao(v, i, 50);
    }
}

DataType vetor_size(Vetor* v){
    return v->length;
}

Vetor* vetor_sub1(Vetor* v, int index){
    int j=1;
    Vetor* vet = vetor_new();
    while (j == 1){
        if (v->length > vet->length){
            vet->vetor = vetor_duplica(vet);
            j=1;
        }
        else{
            j=0;
        }
    }

    if (index >= 0){
        for (int i=0; i<=index; i++){
            vet->vetor[i] = v->vetor[i];
            vet->size++;
        }
        return vet;
    }
    else if (index < 0){
        for (int i=0; index<0; index++){
            vet->vetor[i] = v->vetor[(v->size -1)-i];
            vet->size++;
            i++;
        }
        return vet;
    }
}

Vetor* vetor_sub2(Vetor* v, int start, int end){
    int j=1;
    Vetor* vet = vetor_new();
    while (j == 1){
        if (v->length > vet->length){
            vetor_duplica(vet);
            j=1;
        }
        else{
            j=0;
        }
    }
    for (int i=start; i<=end; i++){
        vet->vetor[i] = v->vetor[i];
        vet->size++;
    }
    return vet;
}

Boolean vetor_shift2(Vetor* v, DataType* ptr){
    *ptr = v->vetor[0];
    float t;
    if (v->size <= v->length){
        for (int i=0; i<v->size; i++){
            v->vetor[i] = v->vetor[i + 1];
        }
        v->size--;
        t = ((float)v->size /v->length);
            if (t < 0.25){
                v->vetor = vetor_diminui(v);
            }
        return true;
    }
    return false;
}

Boolean vetor_get2(Vetor* v, int index, DataType *ptr){
    if (index > v->size -1){
        *ptr = v->vetor[v->size -1];
        return true;
    }
    else if (index <= v->size -1){
        *ptr = v->vetor[index];
        return true;
    }
}

DataType* vetor_get3(Vetor* v, int index){
    int* i = (DataType* )malloc(sizeof(DataType));
    if (index > v->size -1){
        *i = v->vetor[v->size -1];
        return i;
    }
    else if (index <= v->size -1){
        *i = v->vetor[index];
        return i;
    }
}

Boolean ehPar(DataType* ptr){
    return (*ptr % 2 == 0 ? true : false);
}

Boolean ehImpar(DataType* ptr){
    return (*ptr % 2 == 0 ? false : true);
}

Vetor* vetor_filter(Vetor* v, Boolean (*funcao)(DataType*)){
    DataType x = 0;
    DataType* y = (DataType*)malloc(sizeof(DataType));
    Vetor* vet = vetor_new();

    for (int i=0; i<v->size; i++){
        *y = v->vetor[i];
        x = funcao(y);
        if (x == 1){
            if (vet->size == vet->length){
            vet->vetor = vetor_duplica(vet);
            }
            vet->vetor[vet->size] = v->vetor[i];
            vet->size++;
        }
    }
    return vet;
}

int vetor_import(Vetor* v, char* nomeArquivo){
    int cont=0, num;
    char carac;
    arq1 = fopen(nomeArquivo, "r");
    
    if (arq1 == NULL){
        printf("Problemas na CRIACAO do arquivo\n");
    }
    else{
        while(!feof(arq1)){
        carac=fgetc(arq1);
            if (carac != ','){
                arq2 = fopen("copia.txt", "a");
                fputc(carac, arq2);
                fclose(arq2);
            }
            else{
                arq2 = fopen("copia.txt", "r");
                fscanf(arq2, "%d", &num);
                fclose(arq2);
                vetor_add(v,num);
                arq2 = fopen("copia.txt", "w");
                fclose(arq2);
            }
        }
        arq2 = fopen("copia.txt", "r");
        fscanf(arq2, "%d", &num);
        fclose(arq2);
        vetor_add(v,num);
        arq2 = fopen("copia.txt", "w");
        fclose(arq2);
    }
    fclose(arq1);
    return cont;
}

int vetor_save(Vetor* v, char* nomeArquivo){
    int ret;
    arq1 = fopen(nomeArquivo, "wb");
    if (arq1 == NULL){
        printf("Problemas na CRIACAO do arquivo\n");
    }
    else{
        fwrite(&v->size, sizeof(int), 1,arq1);
        fwrite(&v->length, sizeof(int), 1,arq1);
        for (int i=0; i<v->size; i++){
            fwrite(&v->vetor[i], sizeof(int), 1,arq1);
        }
    }
    ret = ((sizeof(v->vetor)*v->size) + sizeof(v->length) + sizeof(v->size));
    vetor_free(v);
    return ret;
}

Vetor* vetor_load(char* nomeArquivo){
    Vetor* vet = vetor_new();
    int num;
    arq1 = fopen(nomeArquivo, "rb");
    if (arq1 == NULL){
        printf("Problemas na CRIACAO do arquivo\n");
    }
    else{
        fread(&num, sizeof(int), 1, arq1);
        vet->size = num;
        fread(&num, sizeof(int), 1, arq1);
        vet->length = num;
        for (int i=0; i<vet->size; i++){
            fread(&num, sizeof(int), 1, arq1);
            vet->vetor[i] = num;
        }
    }
    fclose(arq1);
    return vet;
}