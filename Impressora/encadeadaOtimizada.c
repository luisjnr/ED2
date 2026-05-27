#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "encadeadaOtimizada.h"

int interface(){
	int opc;
	printf("1 - Adicionar Arquivo\n"
		   "2 - Adicionar Arquivo Prioritário\n"
		   "3 - Listar Arquivos\n"
		   "4 - Imprimir Arquivo\n"
		   "5 - Excluir Arquivo\n");
	scanf(" %d", &opc);
	while (getchar() != '\n')
		;
	system("clear");
	return opc;
}

void cadastrarDocument(Body list, int flag){
	char nome[1000];
	int paginas, tamanho;
	printf("===== NEW ARQUIVO =====\n\n"
		   "Nome: ");
	scanf(" %[^\n]s", nome);
	paginas = 1 + rand() % 50;
	tamanho = 100 + rand() % 900;
	new_Document(list, nome, paginas, tamanho, flag);
}

int main(){
	srand(time(NULL));
	Body list = new_List();
	do{
		switch (interface()){
		case 1:
			cadastrarDocument(list, 0);
			alert("Adição concluída!\n");
			break;

		case 2:
			cadastrarDocument(list, 1);
			alert("Adição concluída!\n");
			break;

		case 3:
			listar_Documents(list, 0);
			break;

		case 4:
			listar_Documents(list, 1);
			break;

		case 5:
			deletar_Documents(list);
			break;

		default:
			alert("Erro!\nOpção não existe.\nTente novamente...\n\n");
		}
	} while (1);
}
