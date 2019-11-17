#include <stdio.h>
#include <stdlib.h>



typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

/**
 * Registro utilizado para acomodar cada elemento da pilha (Nó).
 */
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

/**
 * Estrutura usada para representar e armazenar a PILHA com alocação encadeada.
 */
typedef struct{
    No* topo;
    int qtde;
}Pilha;

Pilha* pilha_criar();
Boolean pilha_push(Pilha* p, Tipo elemento);
Tipo* pilha_pop1(Pilha* p);
Boolean pilha_pop2(Pilha* p, Tipo* end);
void pilha_destruir(Pilha* p);
void pilha_imprimir(Pilha* p);
int pilha_posicao(Pilha* p, Tipo elemento);
int pilha_tamanho(Pilha* p);
//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam);
Pilha* pilha_inverter(Pilha* p);
Pilha* pilha_clone(Pilha* p);


/**
 * Cria a pilha e devolve seu endereço.
 * @return o endereço da pilha criada e inicializada.
 */
Pilha* pilha_criar();

/**
 * Desaloca a pilha <p>.
 */

void desalocaNo(No* no){
    if(no == NULL) return;

    desalocaNo(no->prox);
    free(no);
}

void pilha_destruir(Pilha* p){
    if(p == NULL) return;
    
    desalocaNo(p->topo);
    free(p);
    
}



/**
 * Insere o elemento <elemento> no topo da pilha <p>.
 * @param p: Endereço da Pilha em que o elemento será inserido.
 * @param elemento: Elemento a ser inserido na pilha.
 * @return true se a inserção foi realizada com sucesso e false caso contrário
 */

No* novoNo1(Tipo elemento){
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = elemento;
    novo->prox = NULL;
}
No* novoNo2(Tipo elemento, No* proximo){
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = elemento;
    novo->prox = proximo;
}

Boolean pilha_push(Pilha* p, Tipo elemento){

    // No* n = novoNo1(elemento);
    // n->prox = p->topo;
    No* n = novoNo2(elemento, p->topo);
    p->topo = n;
    

    p->qtde++;

}


/**
 * Remove o topo da Pilha <p>, aloca um espaço dinamicamente para armazenar o * elemento removido e devolve o endereço do elemento.
 * @param p: Endereço da Pilha.
 * @return Endereço do elemento removido ou NULL caso contrário.
 */
Tipo* pilha_pop1(Pilha* p);

/**
 * Remove o topo da Pilha <p>, e armazena o elemento removido no endereço 
 * <end> recebido por parâmetro.
 * @param p: Endereço da Pilha.
 * @param end: Endereço de memória onde será armazenado o elemento removido
 * @return true se a remoçao foi realizada com sucesso e false caso contrário
 */
Boolean pilha_pop2(Pilha* p, Tipo* end);


/**
 * Imprime na saída padrão os elementos da pilha
 * @param p: Endereço da Pilha.
 */
void pilha_imprimir(Pilha* p);

/**
 * Devolve a posição do elemento <elemento> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param elemento: Elemento a ser encontrado
 * @return posição do <elemento> em <p> ou -1 caso contrário
 */
int pilha_posicao(Pilha* p, Tipo elemento);

/**
 * Devolve o tamanho da pilha <p>
 * @param p: Endereço da Pilha.
 * @return quantidade de elementos da pilha <p>
 */
int pilha_tamanho(Pilha* p);

//FUNÇÕES ADICIONAIS

/**
 * Insere todos os elementos do vetor <vetor> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param vetor: Endereço do vetor
 * @param tam: tamanho do <vetor>
 * @return quantidade de elementos inseridos na pilha <p>
 */
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam);

/**
 * Inverte a pilha <p>
 * @param p: Endereço da Pilha.
 * @return quantidade de elementos inseridos na pilha <p>
 */
Pilha* pilha_inverter(Pilha* p){
    Pilha* novaPilha = pilha_criar();
    No* aux = p->topo;

    while(aux != NULL){
        pilha_push(novaPilha, aux->dado);
        aux = aux->prox;
    }
    pilha_destruir(p);
    return novaPilha;
}
void pilha_inverter2(Pilha* p){
    
    No* novoTopo = NULL;
    No* aux;

    while(p->topo != NULL){
        //remover o aux da pilha p
        aux = p->topo;
        p->topo = p->topo->prox;
        //inserir no novo encadeamento
        aux->prox = novoTopo;
        novoTopo = aux;
    }
    p->topo = novoTopo;
}

/**
 * Cria um clone da pilha <p>
 * @param p: Endereço da Pilha.
 * @return Endereço da pilha clonada.
 */
Pilha* pilha_clone(Pilha* p);

