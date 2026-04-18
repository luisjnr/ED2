#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TypeProcess{
	char *type;
	int pid;
	int instructions;
	int done;
	struct TypeProcess* next;
	struct TypeProcess* previous;
}TypeProcess;

typedef TypeProcess* Process;

typedef struct TypeBody{
	Process head;
	Process tail;
	Process lastKernel;
	Process current;
	int size;
	int sizePID;
}TypeBody;

typedef TypeBody* Body;

Body new_Body(){
	Body new = malloc(sizeof(TypeBody));
	new->head = NULL;
	new->current = NULL;
	new->lastKernel = NULL;
	new->tail = NULL;
	new->size = 0;
	new->sizePID = 100;
	return new;
}

Body new_Process(Body list, int flag){
	if(!flag){
		Process new = malloc(sizeof(TypeProcess));
		new->type = malloc(strlen("Kernel")+1);
		strcpy(new->type, "Kernel");
		new->pid = list->sizePID;
		new->instructions = 5 + rand() % 5;
		new->done = 0;
		if(!list->head){
			new->next = NULL;
			new->previous = NULL;
			list->head = new;
			list->tail = new;
			list->lastKernel = new;
			list->current = new;
			list->size++;
			list->sizePID++;
			return list;
		}
		if(!list->lastKernel){
			new->next = list->head;
			new->previous = NULL;
			list->head->previous = new;
			list->lastKernel = new;
			list->head = new;
			list->current= new;
			list->size++;
			list->sizePID++;
			return list;
		}
		if(list->lastKernel->pid == list->tail->pid){
			list->tail->next = new;
			new->previous = list->tail;
			new->next = NULL;
			list->tail = new;
			list->lastKernel = new;
			list->current = new;
			list->size++;
			list->sizePID++;
			return list;
		}
		new->next = list->lastKernel->next;
		new->previous = list->lastKernel;
		list->lastKernel->next->previous = new;
		list->lastKernel->next = new;
		list->lastKernel = new;
		list->current = new;
		list->size++;
		list->sizePID++;
		return list;
	}
	else{
		Process new = malloc(sizeof(TypeProcess));
		new->type = malloc(strlen("Usuário")+1);
		strcpy(new->type, "Usuário");
		new->pid = list->sizePID;
		new->instructions = 5 + rand() % 5;
		new->done = 0;
		if(!list->head){
			new->next = NULL;
			new->previous = NULL;
			list->head = new;
			list->tail = new;
			list->current = new;
			list->size++;
			list->sizePID++;
			return list;
		}
		new->next = NULL;
		new->previous = list->tail;
		list->tail->next = new;
		list->tail = new;
		list->current = new;
		list->size++;
		list->sizePID++;
		return list;
	}
	return NULL;
}

Body delete_Process(Body list){
	if(!list->head)	
		return list;
	if(list->head == list->tail){
		free(list->head);
		list->current = NULL;
		list->head = NULL;
		list->lastKernel = NULL;
		list->tail = NULL;
		list->size--;
		return list;
	}
	
	if(list->current == list->head){
		Process temp = list->head;
		if(list->head == list->lastKernel)
			list->lastKernel = NULL;
		list->head = list->head->next;
		list->head->previous = NULL;
		free(temp);
		list->size--;
		list->current = list->tail;
		return list;
	}
	
	if(list->current == list->tail){
		Process temp = list->tail;
		if(list->tail == list->lastKernel)
			list->lastKernel = list->tail->previous;
		list->tail = list->tail->previous;
		list->tail->next = NULL;
		free(temp);
		list->size--;
		list->current = list->tail;
		return list;
	}
	
	if(list->current == list->lastKernel){
		Process temp = list->lastKernel;
		list->lastKernel->next->previous = temp->previous;
		list->lastKernel->previous->next = temp->next;
		list->lastKernel = temp->previous;
		list->current = temp->previous;
		free(temp);
		list->size--;
		return list;
	}
	Process temp = list->current;
	list->current->next->previous = temp->previous;
	list->current->previous->next = temp->next;
	list->current = temp->previous;
	free(temp);
	list->size--;
	return list;
}
