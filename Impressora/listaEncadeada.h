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

void alert(char frase[]){
	system("clear");
	printf("%s", frase);
}

Document new_Document(Document tail, char nome[], int paginas, int tamanho){
	Document novo = malloc(sizeof(Document));
	novo->nome = malloc(strlen(nome)+1);
	strcpy(novo->nome, nome);
	novo->paginas = paginas;
	novo->tamanho = tamanho;
	novo->next = NULL;
	if(!tail)
		return novo;
	tail->next = novo;
	return novo;
}

Document new_DocumentPriority(Document head, char nome[], int paginas, int tamanho){
	Document novo = malloc(sizeof(Document));
	novo->nome = malloc(strlen(nome)+1);
	strcpy(novo->nome, nome);
	novo->paginas = paginas;
	novo->tamanho = tamanho;
	if(!head){
		novo->next = NULL;
		return novo;
	}
	novo->next = head;
	return novo;
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

Document imprimir_Arquivo(Document head){
	if(!head){
		alert("Erro!\nNenhum arquivo foi cadastrado.\nTente novamente...\n");
		return head;
	}
	printf("===== Impressão =====\n\n");
	printf("Nome: %s\n", head->nome);
	printf("Páginas: %d\n", head->paginas);
	printf("Tamanho: %d Bytes\n", head->tamanho);
	Document temp = head;
	free(temp);
	return head->next;
}

void selecionar_Alvo(Document head, char alvo[]){
	do{
		listar_Documents(head);
		Document temphead = head;
		printf("Digite o nome do arquivo: ");
		scanf(" %s", alvo);
		while(temphead){
			if(!strcmp(temphead->nome, alvo))
				return;
			temphead = temphead->next;
		}
		alert("Erro!\nArquivo não foi cadastrado.\nTente novamente...\n");
	} while (1);
}

void deletar_Document(Document* head, Document* tail){
	if(!(*head)){
		alert("Erro!\nNenhum arquivo foi cadastrado.\nTente novamente...\n");
		return;
	}
	char alvo[1000];
	selecionar_Alvo(*head, alvo);
	if(!strcmp((*head)->nome, alvo)){
		Document temp = *head;
		(*head) = (*head)->next;
		free(temp);
		if(!(*head))
			(*tail) = NULL;
		return;
	}
	Document headTemp = *head;
	while(headTemp){
		if(!strcmp(headTemp->next->nome, alvo)){
			Document temp = headTemp->next;
			if(headTemp->next == (*tail)){
				headTemp->next = NULL;
				(*tail) = headTemp;
				free(temp);
				return;
			}
			headTemp->next = temp->next;
			free(temp);
			return;
		}
		headTemp = headTemp->next;
	}
	
}
