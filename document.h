#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Document{
	char* nome;
	int paginas;
	int tamanho;
	struct Document* next;
}Document;

Document* new_Document(Document* head, char nome[], int paginas, int tamanho){
	Document* doc = malloc(sizeof(Document));
	doc->nome = malloc(strlen(nome) + 1);
	strcpy(doc->nome, nome);
	doc->paginas = paginas;
	doc->tamanho = tamanho;
	doc->next = head;
	return doc;
}

void print_Document(Document* doc){
	while(doc){
		printf("Nome: %s\n", doc->nome);
		printf("Paginas: %d\n", doc->paginas);
		printf("Tamanho: %d\n", doc->tamanho);
		doc = doc->next;
	}
}
