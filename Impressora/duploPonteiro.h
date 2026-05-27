#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alert(char frase[]){
	system("clear");
	printf("%s", frase);
}

typedef struct TypeDocument{
	char* nome;
	int paginas, tamanho;
	struct TypeDocument* next;
	struct TypeDocument* prior;
}TypeDocument;

typedef TypeDocument* Document;

typedef struct TypeBody{
	Document head;
	Document tail;
}TypeBody;

typedef TypeBody* Body;

Body new_List(){
	Body list = malloc(sizeof(TypeBody));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

void new_Document(Body list, char nome[], int paginas, int tamanho){
	Document novo = malloc(sizeof(TypeDocument));
	novo->nome = malloc(strlen(nome)+1);
	strcpy(novo->nome, nome);
	novo->paginas = paginas;
	novo->tamanho = tamanho;
	novo->next = NULL;
	if(!list->head){
		novo->prior = NULL;
		list->head = novo;
		list->tail = novo;
		return;
	}
	novo->prior = list->tail;
	list->tail->next = novo;
	list->tail = novo;
	return;
}

void lista_Document(Body list){
	Document head = list->head;
	if(!head){
		alert("Erro!\nNenhum arquivo foi cadastrado.\n\n");
		return;
	}
	printf("====== Lista ======\n\n");
	while(head){
		printf("Nome: %s\n" "Páginas: %d\n" 
		"Tamanho: %d Bytes\n\n", head->nome, head->paginas, head->tamanho);
		head = head->next;
	}
}

void imprimir_Document(Body list){
	if(!list->head){
		alert("Erro!\nNenhum arquivo foi cadastrado.\n\n");
		return;
	}	
	printf("===== Impressão =====\n\n");
	printf("Nome: %s\n" "Páginas: %d\n" 
	"Tamanho: %d Bytes\n\n", list->head->nome, list->head->paginas, list->head->tamanho);
	Document temp = list->head;
	list->head = list->head->next;
	free(temp);
	if(!list->head){
		list->tail = NULL;
		return;
	}
	list->head->prior = NULL;
	return;	
}

void selecionarAlvo(Body list, char alvo[], char frase[]){
	do{
		Document head = list->head;
		printf("===== Seleção =====\n\n");
		lista_Document(list);
		printf("%s", frase);
		scanf(" %s", alvo);
		while(head){
			if(!strcmp(head->nome, alvo))	
				return;
			head = head->next;
		}
		alert("Erro!\nArquivo não existe.\nTente novamente...\n\n");
	} while (1);
}

void deletar_Document(Body list){
	if(!list->head){
		alert("Erro!\nNenhum arquivo foi cadastrado.\n\n");
		return;
	}
	char alvo[1000];
	selecionarAlvo(list, alvo, "Nome do arquivo à ser excluido: ");
	if(list->head == list->tail){
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		alert("Exclusão concluída!\n");
		return;
	}
	if(!strcmp(list->head->nome, alvo)){
		list->head = list->head->next;
		free(list->head->prior);
		list->head->prior = NULL;
		alert("Exclusão concluída!\n");
		return;
	}
	if(!strcmp(list->tail->nome, alvo)){
		Document temp = list->tail;
		list->tail = list->tail->prior;
		list->tail->next = NULL;
		free(temp);
		alert("Exclusão concluída!\n");
		return;
	}
	Document head = list->head;
	while(list->head){
		if(!strcmp(list->head->nome, alvo)){
			Document temp = list->head;
			list->head->next->prior = temp->prior;
			list->head->prior->next = temp->next;
			list->head = head;
			free(temp);
			alert("Exclusão concluída!\n");
			return;
		}
		list->head = list->head->next;
	}
	return;
}

void priorizar_Document(Body list){
	if(!list->head){
		alert("Erro!\nNenhum arquivo foi cadastrado.\n\n");
		return;
	}
	char alvo[1000];
	selecionarAlvo(list, alvo, "Nome do arquivo à ser priorizado: ");
	if(!strcmp(list->head->nome, alvo)){
		alert("Erro!\nArquivo selecionado já está priorizado.\n\n");
		return;
	}	
	if(!strcmp(list->tail->nome, alvo)){
		Document temp = list->tail;
		list->tail = list->tail->prior;
		list->tail->next = NULL; 
		temp->next = list->head;
		list->head->prior = temp;
		temp->prior = NULL;
		list->head = temp;
		return;
	}
	Document head = list->head;
	while(list->head){
		if(!strcmp(list->head->nome, alvo)){
			Document temp = list->head;
			list->head->prior->next = temp->next;
			list->head->next->prior = temp->prior;
			temp->prior = NULL;
			temp->next = head;
			head->prior = temp;
			list->head = temp;
			return;
		}
		list->head = list->head->next;
	}
	return;
}
