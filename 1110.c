#include <stdio.h>
#include <stdlib.h>

//nome: Jogando Cartas Fora

typedef struct Fila {

	int capacidade;
	int *dados;
	int primeiro;
	int ultimo;
	int nItens; 

}Fila;

void criarFila(  Fila *f, int c ) { 

	f->capacidade = c;
	f->dados = (int*) malloc (f->capacidade * sizeof(int));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 

}

void inserir(Fila *f, int v) {

	if(f->ultimo == f->capacidade-1){
		f->ultimo = -1;
	}

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}

int remover(Fila *f) { // pega o item do começoda fila

	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->nItens--;  // um item retirado
	return temp;

}


void mostrarFila( Fila *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%d",f->dados[i++]);

		if (i == f->capacidade)
			i=0;

	}
	printf("\n");

}

int tamanho ( Fila *f){
/*Retorna o tamanho da fila*/
int cont, i,tamanho=0;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		tamanho++;

		if (i == f->capacidade)
			i=0;

	}
	return tamanho;

}

void main () {
	int valor,n,i,count=0,vet[n];
	 Fila umaFila;

	scanf("%d",&n);
	while(n!=0){
		int aux=0,aux2=0,remai;
		count=0;
		criarFila(&umaFila, n);

		for (i = 1; i <= n; i++)
		{
			count++;
			inserir(&umaFila,count);


		}
		//mostrarFila(&umaFila);
		printf("Discarded cards: ");
		while(tamanho(&umaFila)>1){
			aux=remover(&umaFila);
			printf("%d",aux);
			aux2=remover(&umaFila);
			inserir(&umaFila,aux2);
			if(tamanho(&umaFila)>1){
				printf(", ");
			}
		}
		if (tamanho(&umaFila)==1){
			printf("\nRemaining card: ");
			mostrarFila(&umaFila);
		}

		
		

		scanf("%d", &n);
	}
	
}
