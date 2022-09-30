#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "arvoresbinarias.c"
#include "filas.c"
#include "no.c"
#include "pilhas.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

no * carregar_pilha(){
	no *pilha = NULL;
	
	FILE* arquivo;
	int num;
	
	arquivo = fopen("dados.txt","r");
	while(!feof(arquivo)){
		fscanf(arquivo,"%i\n", &num);
		push(&pilha, num);
	}
	fclose(arquivo);
	return pilha;
}


no * carregar_fila(){
	no *fila = NULL;
	FILE* arquivo;
	int num;
	
	arquivo = fopen("dados.txt","r");
	while(!feof(arquivo)){
		
		fscanf(arquivo,"%i\n", &num);
		qinsert(&fila, num);
	}
	fclose(arquivo);
	return fila;
}

nodetree * carregar_arvore(){
	nodetree *arvore = NULL;
	
	FILE* arquivo;
	int num;
	int vez = 1;
	
	arquivo = fopen ("dados.txt","r");
	while(!feof(arquivo)){
		fscanf(arquivo,"%i\n", &num);
		if(vez==1){
			arvore = maketree(num);
			vez = 2;
		}
		else
			insert_binary_tree(arvore, num);
	}
	fclose(arquivo);
	
	return arvore;
}


int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"");
	
	LARGE_INTEGER tempoInicial, tempoFinal;
	int tempoPilha, tempoFila, tempoArvore;
	
	no *pilha = NULL;
	no *filha = NULL;
	nodetree *arvore;
	
	QueryPerformanceCounter (&tempoInicial);
	arvore = carregar_arvore();
	QueryPerformanceCounter(&tempoFinal);
	tempoArvore = tempoFinal.QuadPart - tempoInicial.QuadPart;
	
	QueryPerformanceCounter(&tempoInicial);
	pilha = carregar_pilha();
	QueryPerformanceCounter(&tempoFinal);
	tempoPilha = tempoFinal.QuadPart - tempoInicial.QuadPart;
	
	QueryPerformanceCounter(&tempoInicial);
	fila = carregar_fila();
	QueryPerformanceCounter(&tempoFinal);
	tempoFila = tempoFinal.QuadPart - tempoInicial.QuadPart;
	
	printf("\nPilha\n");
	percorrer_pilha(&pilha);
	printf("Tempo gasto: %i\n", tempoPilha);

	printf("\nFila\n");
	percorrer_fila(&fila);
	printf("Tempo gasto: %i\n", tempoFila);

	printf("\nArvores\n");
	percorrer_ordem(arvore);
	printf("Tempo gasto: %i\n", tempoArvore);

	return 0;
}
