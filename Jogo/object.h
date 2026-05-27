#define new(Type) new_##Type()

typedef enum{
	PLAYER, ARMA, NPC,
}TypeNode;

typedef struct Node{
	void* item;
	TypeNode type;
	struct Node* next;
	struct Node* prev;
}Node;

typedef Node* Object;

Object new_Object(){
	Object novo = malloc(sizeof(Node));
	novo->next = NULL;
	novo->prev = NULL;
	novo->item = NULL;
	return novo;
}

void destroy(Object objeto){
	free(objeto->item);
	free(objeto);
}

