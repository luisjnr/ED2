#define new(Type) new_##Type()

typedef struct _List{
	Object head;
	Object tail;
	int size;
	void (*enqueue)();
	void (*print)();
	void (*bonus)();
}_List;

typedef _List* List;

void list_Bonus();
void list_Print();
void list_Enqueue();

List new_List(){
	List list = malloc(sizeof(_List));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->enqueue = list_Enqueue;
	list->bonus = list_Bonus;
	list->print = list_Print;
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

void list_Print(List self, void (*print)()){
	if(!self->head) return;
	Object current = self->head;
	while(current){
		print(current);
		current = current->next;
	}
}

void list_Bonus(List self, Object contexto, void (*bonus)()){
	if(!self->head) return;
	Object current = self->head;
	while(current){
		bonus(current, contexto);
		current = current->next;
	}
}
