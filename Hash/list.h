#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

typedef struct _List{
	Object head;
	Object tail;
	int size;
	void (*enqueue)();
	void (*push)();
	Object (*pop)();
	void (*print)();
	void (*bonus)();
	void (*clear)();
	void (*del)();
	Object (*get)();
}_List;

typedef _List* List;

void list_Bonus();
void list_Print();
void list_Enqueue();
void list_Push();
void list_Clear();
void list_Delete();
Object list_Pop();
Object list_Get();

List new_List(){
	List list = malloc(sizeof(_List));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->enqueue = list_Enqueue;
	list->bonus = list_Bonus;
	list->print = list_Print;
	list->clear = list_Clear;
	list->push = list_Push;
	list->pop = list_Pop;
	list->get = list_Get;
	list->del = list_Delete;
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
		self->tail = novo;
	}
	self->size++;
}

void list_Push(List self, Object novo){
	if(!self->head){
		self->head = novo;
		self->tail = novo;
	} 
	else{
		self->head->prev = novo;
		novo->next = self->head;
		self->head = novo;
	}
	self->size++;
}

void list_Print(List self){
	if(!self->head) return;
	Object current = self->head;
	while(current){
		current->print(current);
		current = current->next;
	}
}

Object list_Pop(List self){
	if(!self->head) return NULL;
	Object current = self->head;
	self->head = current->next;
	current->next = NULL;
	if(!self->head){
		self->tail = NULL;
		return current;
	}	
	self->head->prev = NULL;
	self->size--;
	return current;
}

void list_Clear(List self){
	if(!self->head) return;
	Object current = self->head;
	while(current){
		current->destroy(current);
		current = current->next;
		self->size--;
	}
	self->head = NULL;
	self->tail = NULL;
}

Object list_Get(List self, int pos){
	if(!self->head || pos < 0 || pos >= self->size) return NULL;
	Object current = self->head;
	for (int i = 0; i < pos; i++)
		current = current->next;
	return current;
}

void list_Bonus(List self, Object contexto, void (*bonus)()){
	if(!self->head) return;
	Object current = self->head;
	while(current){
		bonus(current, contexto);
		current = current->next;
	}
}

void list_Delete(List self, int pos){
	if(!self->head || pos < 0 || pos >= self->size) return;
	Object current = self->head;
	for (int i = 0; i < pos; i++)
		current = current->next;
	if(self->head == current){
		self->head = current->next;
		current->destroy(current);
		if(!self->head){
			self->tail = NULL;
			self->size--;
			return;
		}
		self->head->prev = NULL;
		self->size--;
		return;
	}
	if(self->tail == current){
		self->tail = current->prev;
		current->destroy(current);
		if(!self->tail){
			self->head = NULL;
			self->size--;
			return;
		}
		self->tail->next = NULL;
		self->size--;
		return;
	}
	current->prev->next = current->next;
	current->next->prev = current->prev;
	current->destroy(current);
	self->size--;
}
