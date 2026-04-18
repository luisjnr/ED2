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

typedef struct TypeBody{
	Document head;
	Document tail;
}TypeBody;

typedef TypeBody* Body;

void alert(char frase[]){
	system("clear");
	printf("%s", frase);
}

Body new_List(){
	Body list = malloc(sizeof(TypeBody));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

Body new_Document(Body list, char nome[], int paginas, int tamanho, int flag){
	Document novo = malloc(sizeof(Document));
	novo->nome = malloc(strlen(nome));
	strcpy(novo->nome, nome);
	novo->paginas = paginas;
	novo->tamanho = tamanho;
	if(!flag){
		if(!list->head)
			list->head = novo;
		novo->next = NULL;
		if(!list->tail){
			list->tail = novo;
			return list;
		}
		list->tail->next = novo;
		list->tail = novo;
		return list;
	}
	else{
		if(!list->tail){
			novo->next = NULL;
			list->tail = novo;
			list->head = novo;
			return list;
		}
		novo->next = list->head;
		list->head = novo;
		return list;
	}
}

Body listar_Documents(Body list, int flag){
	if(!list->head){
		alert("Erro!\nNenhum arquivo foi cadastrado.\nTente novamente...\n");
		return list;
	}
	if(!flag){
		Document head = list->head;
		printf("===== LISTA =====\n\n");
		while(head){
			printf("Arquivo: %s\n", head->nome);
			printf("Páginas: %d\n", head->paginas);
			printf("Tamanho: %d Bytes\n\n", head->tamanho);
			head = head->next;
		}
	}
	else{
		Document temp = list->head;
		printf("===== ARQUIVO =====\n\n");
		printf("Arquivo: %s\n", list->head->nome);
		printf("Páginas: %d\n", list->head->paginas);
		printf("Tamanho: %d Bytes\n\n", list->head->tamanho);
		list->head = list->head->next;
		free(temp);
		if(!list->head)
			list->tail = NULL;
		return list;
	}
	return list;
}

void selecionarAlvo(Body list, char alvo[]){
	do{
		Document head = list->head;
		int flag = 0;
		printf("===== EXCLUSÃO =====\n\n");
		listar_Documents(list, 0);	
		printf("Nome do arquivo: ");
		scanf(" %s", alvo);
		while(head){
			if(!strcmp(head->nome, alvo)){
				flag = 1;
				break;
			}
			head = head->next;
		} 
		if(flag)
			break;
		else
			alert("Erro!\nArquivo não existe.\nTente novamente...\n\n");
	} while (1);
}

Body deletar_Documents(Body list){
	if(!list->head){
		alert("Erro!\nNenhum arquivo foi cadastrado.\n\n");
		return list;
	}
	char alvo[1000];
	selecionarAlvo(list, alvo);
	if(!strcmp(list->head->nome, alvo)){
		Document temp = list->head;
		list->head = list->head->next;
		free(temp);
		if(!list->head)
			list->tail = NULL;
		return list;
	}
	Document head = list->head;
	while(list->head){
		if(!strcmp(list->head->next->nome, alvo)){
			Document temp = list->head->next;
			if(!strcmp(list->tail->nome, alvo)){
				list->tail = list->head;
				list->tail->next = NULL;
				free(temp);
				list->head = head;
				return list;
			}
			list->head->next = temp->next;
			list->head = head;
			free(temp);
			return list;
		}
		list->head = list->head->next;
	}
	return list;
}
