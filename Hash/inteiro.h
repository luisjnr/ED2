#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

typedef struct _Int{
	int num;
}_Int;

typedef _Int* Int;

void setInt();
void printInt();
void destroyInt();

Object new_Int(int num, int type){
	Object novo = new(Object);
	novo->type = type;
	novo->item = malloc(sizeof(_Int));
	novo->set = setInt;
	novo->print = printInt;
	novo->destroy = destroyInt;
	setInt(novo, num);
	return novo;
}

void setInt(Object self, int num){
	Int novo = self->item;
	novo->num = num;
}

void printInt(Object self){
	Int inteiro = self->item;
	printf("====== Int ======\n");
	printf("Número: %d\n\n", inteiro->num);
}

void destroyInt(Object objeto){
	free(objeto->item);
	free(objeto);
}

