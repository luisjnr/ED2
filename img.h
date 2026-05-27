#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alert(char frase[]){
	system("clear");
	printf("%s", frase);
}

typedef struct TypeContainer{
	int id;
	int action;
	struct TypeContainer* next;
	struct TypeContainer* prior;
}TypeContainer;

typedef TypeContainer* Container;

typedef struct TypeImagem{
	char *type;
	int size;
	int id;
	Container headContainer;
	Container tailContainer;
	int idContainer;
	struct TypeImagem* next;
	struct TypeImagem* prior;
}TypeImagem;

typedef TypeImagem* Imagem;

typedef struct TypeBody{
	Imagem head;
	Imagem tail;
	int id;
}TypeBody;

typedef TypeBody* Body;

Body new_list(){
	Body new = malloc(sizeof(TypeBody));
	new->head = NULL;
	new->tail = NULL;
	new->id = 1;
	return new;
}

void new_imagem(Body list, char type[], int size){
	Imagem new = malloc(sizeof(TypeImagem));
	new->type = malloc(strlen(type) + 1);
	strcpy(new->type, type);
	new->size = size;
	new->id = list->id;
	new->idContainer = 1;
	new->headContainer = NULL;
	new->tailContainer = NULL;
	list->id++;
	if(!list->head){
		new->prior = NULL;
		new->next = NULL;
		list->head = new;
		list->tail = new;
		return;
	}
	list->tail->next = new;
	new->prior = list->tail;
	list->tail = new;
}

void listarImagem(Body list){
	if(!list->head){
		alert("Nenhuma imagem foi baixada.\n\n");
		return;
	}
	printf("====== Imagens Baixadas ======\n\n");
	Imagem head = list->head;
	while(head){
		printf("ID: %d\n" "Tipo: %s\n" 
		"Tamanho: %d Bytes\n\n", head->id, head->type, head->size);
		head = head->next;
	}
}

void new_container(Body list, int id){
	Imagem head = list->head;
	while(head){
		if(head->id == id){
			Container new = malloc(sizeof(TypeContainer));
			new->action = 1;
			new->id = list->head->idContainer;
			head->idContainer++;
			if(!head->headContainer){
				new->next = NULL;
				new->prior = NULL;
				head->headContainer = new;
				head->tailContainer = new;
				return;
			}
			head->tailContainer->next = new;
			new->prior = list->head->tailContainer;
			head->tailContainer = new; 
			return;
		}
		list->head = list->head->next;
	}
	alert("ID não existe.\n\n");
}

void listarContainer(Body list){
	if(!list->head){
		alert("Nenhuma imagem foi baixada.\n\n");
		return;
	}
	printf("====== Containers ======\n\n");
	Imagem head = list->head;
	int flag = 0;
	while(head){
		Container headContainer = head->headContainer;
		while(headContainer){
			printf("ID IMG: %d\n" "ID Container: %d\n"
			, head->id, headContainer->id);
			if(headContainer->action)
				printf("Ativo\n\n");
			else
				printf("Inativo\n\n");
			flag = 1;
			headContainer = headContainer->next;
		}	
		head = head->next;
	}
	if(!flag)
		alert("Não existem containers vinculados as imagens baixadas.\n\n");
}



void interromperContainer(Body list){
	if(!list->head){
		alert("Nenhuma imagem foi baixada.\n\n");
		return;
	}
	printf("====== Interromper Container ======\n\n");
	listarImagem(list);
	int idImg, idContainer;
	printf("Digite o ID da imagem: ");
	scanf(" %d", &idImg);
	Imagem head = list->head;
	while(head){
		if(head->id == idImg){
			if(!head->headContainer){
				alert("Não existem containers nessa imagem.\n\n");
			}
			Container headContainer = head->headContainer;
			printf("====== Lista Containers ======\n\n");
			while(headContainer){
				printf("ID IMG: %d\n" "ID Container: %d\n"
				, head->id, headContainer->id);
				if(headContainer->action)
					printf("Ativo\n\n");
				else
					printf("Inativo\n\n");
				headContainer = headContainer->next;
			}
			printf("Digite o ID do container: ");
			scanf(" %d", &idContainer);
			headContainer = head->headContainer;
			while(headContainer){
				if(headContainer->id == idContainer){
					if(!headContainer->action){
						alert("Container já está inativo.\n\n");
					}
					headContainer->action = 0;
					return;
				}
				headContainer = headContainer->next;
			}
		}
		head = head->next;
	}
	alert("Container não existe.\n\n");
}

void iniciarContainer(Body list){
	if(!list->head){
		alert("Nenhuma imagem foi baixada.\n\n");
		return;
	}
	printf("====== Iniciar Container ======\n\n");
	listarImagem(list);
	int idImg, idContainer;
	printf("Digite o ID da imagem: ");
	scanf(" %d", &idImg);
	Imagem head = list->head;
	while(head){
		if(head->id == idImg){
			if(!head->headContainer){
				alert("Não existem containers nessa imagem.\n\n");
			}
			Container headContainer = head->headContainer;
			printf("====== Lista Containers ======\n\n");
			while(headContainer){
				printf("ID IMG: %d\n" "ID Container: %d\n"
				, head->id, headContainer->id);
				if(headContainer->action)
					printf("Ativo\n\n");
				else
					printf("Inativo\n\n");
				headContainer = headContainer->next;
			}
			printf("Digite o ID do container: ");
			scanf(" %d", &idContainer);
			headContainer = head->headContainer;
			while(headContainer){
				if(headContainer->id == idContainer){
					if(headContainer->action){
						alert("Container já está ativo.\n\n");
					}
					headContainer->action = 1;
					return;
				}
				headContainer = headContainer->next;
			}
		}
		head = head->next;
	}
	alert("Container não existe.\n\n");
}

void excluirImagem(Body list){
	if(!list->head){
		alert("Nenhuma imagem foi baixada.\n\n");
		return;
	}
	printf("====== Exclusão de Imagem ======\n\n");
	listarImagem(list);
	printf("Digite o ID da imagem: ");
	int id;
	scanf(" %d", &id);
	Imagem head = list->head;
	if(list->head->id == id){
		if(list->head->headContainer){
			alert("Erro!\nExistem containers vinculados a essa imagem.\n\n");
			return;
		}
		list->head = list->head->next;
		free(head);
		if(!list->head){
			list->tail = NULL;
			return;
		}
		list->head->prior = NULL;
		return;
	}
	if(list->tail->id == id){
		if(list->head->headContainer){
			alert("Erro!\nExistem containers vinculados a essa imagem.\n\n");
			return;
		}
		Imagem temp = list->tail;
		list->tail = list->tail->prior;
		list->tail->next = NULL;
		free(temp);
		return;
	}
	while(head){
		if(head->id == id){
			if(head->headContainer){
				alert("Erro!\nExistem containers vinculados a essa imagem.\n\n");
				return;
			}
			Imagem temp = head;
			head->prior->next = head->next;
			head->next->prior = head->prior;
			free(temp);
			return;
		}
		head = head->next;
	}
	alert("Imagem não existe.\n\n");
}

void excluirContainer(Body list){
	if(!list->head){
		alert("Nenhuma imagem foi baixada.\n\n");
		return;
	}	
	printf("====== Exclusão de Container ======\n\n");
	listarImagem(list);
	int idImg, idContainer;
	printf("Digite o ID da imagem: ");
	scanf(" %d", &idImg);
	Imagem head = list->head;
	while(head){
		if(head->id == idImg){
			if(!head->headContainer){
				alert("Não existem containers vinculados a essa imagem.\n\n");
				return;
			}
			Container headContainer = head->headContainer;
			printf("====== Lista Containers ======\n\n");
			while(headContainer){
				printf("ID IMG: %d\n" "ID Container: %d\n"
				, head->id, headContainer->id);
				if(headContainer->action)
					printf("Ativo\n\n");
				else
					printf("Inativo\n\n");
				headContainer = headContainer->next;
			}
			printf("Digite o ID do conteiner: ");
			scanf(" %d", &idContainer);
			headContainer = head->headContainer;
			if(headContainer->id == idContainer){
				if(head->headContainer->action){
					alert("Impossível excluir, container está ativo.\n\n");
					return;
				}
				head->headContainer = head->headContainer->next;
				free(headContainer);
				if(!head->headContainer){
					head->tailContainer = NULL;
					return;
				}
				head->headContainer->prior = NULL;
				return;
			}
			if(head->tailContainer->id == idContainer){
				if(head->tailContainer->action){
					alert("Impossível excluir, container está ativo.\n\n");
					return;
				}
				Container temp = head->tailContainer;
				head->tailContainer = head->tailContainer->prior;
				head->tailContainer->next = NULL;
				free(temp);
				return;
			}
			while(headContainer){
				if(headContainer->id == idContainer){
					if(headContainer->action){
						alert("Impossível excluir, container está ativo.\n\n");
						return;
					}
					Container temp = headContainer;
					headContainer->prior->next = headContainer->next;
					headContainer->next->prior = headContainer->prior;
					free(temp);
					return;
				}
				headContainer = headContainer->next;
			}
		}
		head = head->next;
	}
	alert("Container ou Imagem não existem.\n\n");
}
