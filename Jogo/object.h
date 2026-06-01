#define new(Type) new_##Type()

typedef enum{
	PLAYER, ARMA, NPC,
}TypeNode;

typedef struct Node{
	void* item;
	TypeNode type;
	struct Node* next;
	struct Node* prev;
	void (*set)();
	void (*print)();
	void (*destroy)();
}Node;

typedef Node* Object;

void destroy(Object objeto);           

Object new_Object(){
	Object novo = malloc(sizeof(Node));
	novo->next = NULL;
	novo->prev = NULL;
	novo->item = NULL;
	novo->destroy = destroy;
	return novo;
}

void print_object(Object self) {
    if(self)
		self->print(self);
	return;
}

void destroy(Object objeto){
	free(objeto->item);
	free(objeto);
}



