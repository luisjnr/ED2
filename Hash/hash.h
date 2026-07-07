#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

typedef struct _Hash{
	List* buckets;
	int size;
	void (*insert)();
	void (*print)();
	void (*del)();
	List (*search)();
}_Hash;

typedef _Hash* Hash;

int hash(Hash hs, int cod){
	int key = cod % hs->size;
	return key;
}

void insert_Hash(Hash hs, int key, Object self){
	List lst = hs->buckets[hash(hs, key)];
	lst->enqueue(lst, self);
}

void print_Hash(Hash hs, int key){
	List lst = hs->buckets[hash(hs, key)];
	lst->print(lst);
}

void delete_Hash(Hash hs, int key, int item){
	List lst = hs->buckets[hash(hs, key)];
	lst->del(lst, item);
}

List search_Hash(Hash hs, int key){
	List lst = hs->buckets[hash(hs, key)];
	return lst;
}

Hash new_Hash(int size){
	Hash hs = malloc(sizeof(_Hash));
	hs->buckets = malloc(size * sizeof(List));
	for (int i = 0; i < size; i++){
		List lst = new(List);
		hs->buckets[i] = lst;
	}	
	hs->size = size;
	hs->insert = insert_Hash;
	hs->print = print_Hash;
	hs->del = delete_Hash;
	hs->search = search_Hash;
	return hs;
}
