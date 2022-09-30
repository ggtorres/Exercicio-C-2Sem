#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void mensagem(char txt[]){
	
	puts("\n");
	puts(txt);
	puts("Pressione <enter> para continuar");
	getch();
}

void cadastro (){
	
	int numero;
	printf("Entre com o numero ");
	scanf("%i", &numero);
	
	FILE*arquivo;
	arquivo = fopen ("dados.txt","a+");
	
	fprintf(arquivo,"%i\n", numero);
	fclose(arquivo);
	
	mensagem("Cadastro efetuado com sucesso!");
}

void listar(){
	
	int numero;
	FILE* arquivo;
	
	printf("\n\nNumero cadastrados: \n");
	
	arquivo = fopen("dados.txt","r");
	while(!feof(arquivo))
	{
		fscanf(arquivo,"%i\n", &numero);
		printf("%i\t", numero);
	}
	fclose(arquivo);
	
	mensagem("Fim da listagem");
}

void limpar (){
	
	FILE* arquivo;
	arquivo = fopen("dados.txt", "w");
	fclose(arquivo);
	
	mensagem("Limpeza efetuada!");
}

int main(){
	
	
	setlocale(LC_ALL, "");
	
	int resp=0;
	
	while(resp!=4){
		
		system("cls");
		
		printf("1- Cadastre o numero\n");
		printf("2- Listar numeros cadastrados\n");
		printf("3- Limpar numeros cadastrados\n");
		printf("4- Sair\n");
		scanf("%i", &resp);
		
		switch(resp){
			
			case 1: cadastro();
				break;
			
			case 2: listar();
				break;
			
			case 3: limpar();
				break;
			
			case 4:
				break;
		
			default: mensagem("Opcao invalida");
				break;
		}
	
	return 0;
	}
}
