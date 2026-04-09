#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TypeDocument{
	char *nome;
	int paginas;
	int tamanho;
	struct TypeDocument* next;
}TypeDocument;

typedef TypeDocument* Document;

typedef struct Body{
	Document head;
	Document tail;
}Body;

void alert(char frase[]){
	system("clear");
	printf("%s", frase);
}

Body* new_Document(Body* list, char nome[], int paginas, int tamanho){
	Document novo = malloc(sizeof(Document));
	novo->nome = malloc(strlen(nome));
	strcpy(novo->nome, nome);
	novo->paginas = paginas;
	novo->tamanho = tamanho;
	novo->next = NULL;
	if(!list->head)
		list->head = novo;
	if(!list->tail){
		list->tail = novo;
		return list;
	}
	list->tail->next = novo;
	list->tail = novo;
	return list;
}

void listar_Documents(Document head){
	if(!head){
		alert("Erro!\nNenhum arquivo foi cadastrado.\nTente novamente...\n");
		return;
	}
	printf("===== LISTA =====\n\n");
	while(head){
		printf("Arquivo: %s\n", head->nome);
		printf("Páginas: %d\n", head->paginas);
		printf("Tamanho: %d Bytes\n\n", head->tamanho);
		head = head->next;
	}
}
