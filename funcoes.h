#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=-1, true=1} Boolean;

typedef struct node{
	int linha;
	int coluna;
	int valor;
	struct node* direita;
	struct node* baixo;		
	struct node* esquerda;
	struct node* cima;
	
}Node;

typedef struct{
	Node** linhas;	//ponteiro para o vetor cujas células são ponteiros de nós
	Node** colunas;	//ponteiro para o vetor cujas células são ponteiros de nós
	int numLinhas;	//Quantidade de linhas da matriz
	int numColunas;	//Quantidade de colunas da matriz
}Matriz;


//FUNÇÕES
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas);
void matriz_desalocar(Matriz* m);
void matriz_imprimir(Matriz* m);
int matriz_atribuir(Matriz* m, int linha, int coluna, int valor);
int matriz_acessar(Matriz* m, int linha, int coluna);
//AUXILIARES
void criaSentinela(Matriz* m);
Node* novoNode(int linha, int coluna, int valor);
Node* getNoLinha(Matriz* m, int linha, int posicao, int valor);
void insereEsquerda(Node* node, Node* aux);
Node* getNoColuna(Matriz* m, int coluna, int posicao);
void insereCima(Node* node, Node* aux);


//IMPLEMENTAÇÕES
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas){
    Matriz* nova = (Matriz*)malloc(sizeof(Matriz));
	nova->linhas = (Node**)calloc(qtdeLinhas,sizeof(Node*));
	nova->colunas = (Node**)calloc(qtdeColunas,sizeof(Node*));
	nova->numLinhas = qtdeLinhas;
	nova->numColunas = qtdeColunas;
	criaSentinela(nova);
	return nova;
}

void criaSentinela(Matriz* m){
	for (int i=0; i<m->numLinhas; i++){
		m->linhas[i] = (Node*)malloc(sizeof(Node));
		m->linhas[i]->direita = m->linhas[i];
		m->linhas[i]->esquerda = m->linhas[i];
	}
	for (int i=0; i<m->numColunas; i++){
		m->colunas[i] = (Node*)malloc(sizeof(Node));
		m->colunas[i]->cima = m->colunas[i];
		m->colunas[i]->baixo = m->colunas[i];
	}
}

void matriz_desalocar(Matriz* m){
	Node* aux;
	for (int i=0; i<m->numLinhas; i++){
		aux = m->linhas[i]->esquerda;
		while(aux != m->linhas[i]){
			aux = aux->esquerda;
			free(aux->direita);
		}
		free(aux);
	}
	for (int i=0; i<m->numColunas; i++){
		aux = m->colunas[i];
		free(aux);
	}
	free(m);
}

void matriz_imprimir(Matriz* m){
	printf("\n");
	Node* aux;
	for (int i=0; i<m->numColunas; i++){
		printf("_______");
	}
	printf("\n");
	for (int i=0; i<m->numLinhas; i++){
		aux = m->linhas[i]->direita;
		for (int j=0; j<m->numColunas; j++){
			if(aux->linha == i && aux->coluna == j){
				printf("%d\t", aux->valor);
				aux = aux->direita;
			} 
			else printf("0\t");
		}
		printf("\n");
	}
	for (int i=0; i<m->numColunas; i++){
		printf("_______");
	}
}

int matriz_atribuir(Matriz* m, int linha, int coluna, int valor){
	if (linha >= m->numLinhas || coluna >= m->numColunas || linha < 0 || coluna < 0) return false;
	Node* node = novoNode(linha, coluna, valor);
	Node* aux = getNoLinha(m, linha, coluna, valor);
	if (aux != NULL){
		insereEsquerda(node, aux);
		aux = getNoColuna(m, coluna, linha);
		insereCima(node, aux);
	}
	return valor;
}

Node* getNoLinha(Matriz* m, int linha, int posicao, int valor){
	Node* aux = m->linhas[linha]->direita;
	for (int j=0; j<m->numColunas; j++){
		if (aux == m->linhas[linha]) return aux;
		else if (aux->coluna != posicao){
			if (aux->coluna < posicao) aux = aux->direita;
			else return aux;
		}
		else if(aux->coluna == posicao){
			aux->valor = valor;
			return NULL;
		}
	}
}

Node* novoNode(int linha, int coluna, int valor){
	Node* novo = (Node*)malloc(sizeof(Node));
	novo->valor = valor;
	novo->linha = linha;
	novo->coluna = coluna;
	return novo;
}

void insereEsquerda(Node* node, Node* aux){
	node->direita = aux;
	node->esquerda = aux->esquerda;
	aux->esquerda->direita = node;
	aux->esquerda = node;
}

Node* getNoColuna(Matriz* m, int coluna, int posicao){
	Node* aux = m->colunas[coluna]->baixo;
	for (int i=0; i<m->numLinhas; i++){
		if (aux == m->colunas[coluna]) return aux;
		else if (aux->linha != posicao){
			if (aux->linha < posicao) aux = aux->baixo;
			else return aux;
		}
		else{
			aux = aux->baixo;
			return aux;
		}
	}
}

void insereCima(Node* node, Node* aux){
	node->baixo = aux;
	node->cima = aux->cima;
	aux->cima->baixo = node;
	aux->cima = node;
}

int matriz_acessar(Matriz* m, int linha, int coluna){
	if (linha >= m->numLinhas || coluna >= m->numColunas || linha < 0 || coluna < 0) return false;
	Node* aux = m->linhas[linha]->direita;
	while(aux !=m->linhas[linha]){
		if (aux->coluna == coluna) return aux->valor;
		else aux = aux->direita;
	}
	return 0;
}