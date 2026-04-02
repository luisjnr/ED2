#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "document.h"

int interface(){
	int opc;
	printf("1 - Criar Documento\n" "2 - Listar Documentos\n");
	scanf(" %d", &opc);
	while(getchar() != '\n');
	return opc;
}

void* criar_Document(Document* head){
	char nome[1000];
	int paginas, tamanho;
	printf("Nome do arquivo: ");
	scanf(" %[^\n]s", nome);
	
	do{
		printf("Qntde. de Páginas: ");
		scanf(" %d", &paginas);
	}while(paginas<=0);
	
	tamanho = 100+ rand() % 1000;
	return new_Document(head, nome, paginas, tamanho);
}

int main(){
	srand(time(NULL));
	Document* head = NULL;

	do{
		switch (interface())
		{
			case 1: head = criar_Document(head);
				
				break;
			case 2:	print_Document(head);
				
				break;
			default:
		}
	} while (1);
}
