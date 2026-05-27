#define new(Type) new_##Type()

typedef struct _List{
	Object head;
	Object tail;
	int size;
}_List;

typedef _List* List;

List new_List(){
	List list = malloc(sizeof(_List));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void list_Enqueue(List self, Object novo){
	if(!self->head){
		self->head = novo;
		self->tail = novo;
	}
	else{
		self->tail->next = novo;
		novo->prev = self->tail;
		novo->next = NULL;
		self->tail = novo;
	}
	self->size++;
}

void list_Print(List self, void print(), char item[]){
	if(!self->head) return;
	Object current = self->head;
	printf("====== %s ======\n\n", item);
	while(current){
		print(current);
		current = current->next;
	}
}

void list_Bonus(List self, Object contexto, void bonus()){
	if(!self->head) return;
	Object current = self->head;
	while(current){
		bonus(current, contexto);
		current = current->next;
	}
}
