#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

typedef struct Node{
	void* item;
	int type;
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
	return novo;
}

void print_object(Object self) {
    if(self)
		self->print(self);
}
