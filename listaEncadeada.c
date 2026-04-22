#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listaEncadeada.h"

int interface(){
	int opc;
	printf("1 - Adicionar Arquivo\n" "2 - Adicionar Arquivo Prioritário\n"
	"3 - Listar Arquivos\n" "4 - Imprimir Arquivo\n" "5 - Excluir Arquivo\n");
	scanf(" %d", &opc);
	while(getchar() != '\n');
	system("clear");
	return opc;
}

Document cadastrarDocument(Document head, Document tail, int flag){
		char nome[1000];
		int paginas, tamanho;
		printf("===== NEW ARQUIVO =====\n\n" 
		"Nome: ");
		scanf(" %[^\n]s", nome);
		paginas = 1 + rand() % 50;
		tamanho = 100 + rand() % 900;
	if(!flag)
		return new_Document(tail, nome, paginas, tamanho);
	else
		return new_DocumentPriority(head, nome, paginas, tamanho);
}

int main(){
	srand(time(NULL));
	Document head = NULL;
	Document tail = NULL;
	do{
		switch (interface()){
			case 1: tail = cadastrarDocument(head, tail, 0);
				if(!head)
					head = tail;
				break;
				
			case 2: head = cadastrarDocument(head, tail, 1);
				if(!tail)
					tail = head;
				break;
				
			case 3: listar_Documents(head); 
				break;
				
			case 4: head = imprimir_Arquivo(head);
				if(!head)
					tail = NULL;
				break;
				
			case 5: deletar_Document(&head, &tail);
				break;
				
			default: alert("Erro!\nOpção não existe.\nTente novamente...\n\n");
		}
	} while (1);
	
}
