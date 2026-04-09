#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listaGenerica.h"

int interface(){
	int opc;
	printf("1 - Adicionar Arquivo\n" "2 - Adicionar Arquivo Prioritário\n"
	"3 - Listar Arquivos\n" "4 - Listar Primeiro Arquivo da Fila\n" "5 - Excluir Arquivo\n");
	scanf(" %d", &opc);
	while(getchar() != '\n');
	system("clear");
	return opc;
}

Body* cadastrarDocument(Body* list){
	char nome[1000];
	int paginas, tamanho;
	printf("===== NEW ARQUIVO =====\n\n" 
	"Nome: ");
	scanf(" %[^\n]s", nome);
	paginas = 1 + rand() % 50;
	tamanho = 100 + rand() % 900;
	return new_Document(list, nome, paginas, tamanho);
}

int main(){
	srand(time(NULL));
	Body* list;
	list->head = NULL;
	list->tail = NULL;
	do{
		switch (interface()){
			case 1: list = cadastrarDocument(list); 
				break;
				
			case 2:
				break;
				
			case 3: listar_Documents(list->head); 
				break;
				
			case 4:
				break;
				
			case 5:
				break;
			default: alert("Erro!\nOpção não existe.\nTente novamente...\n\n");
		}
	} while (1);
	
}
