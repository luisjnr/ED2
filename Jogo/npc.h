#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

typedef enum{
	DRAGAO, MONSTRO, DEMONIO,
}Tipo;

typedef struct _Npc{
	int id;
	int hp;
	Tipo tipo;
}_Npc;

typedef _Npc* Npc;

void setNpc();
void printNpc();
void destroyNpc();

Object new_Npc(int id, int hp, Tipo tipo){
	Object novo = new(Object);
	novo->type = 2;
	novo->item = malloc(sizeof(_Npc));
	novo->set = setNpc;
	novo->print = printNpc;
	novo->destroy = destroyNpc;
	setNpc(novo, id, hp, tipo);
	return novo;
}

void setNpc(Object self, int id, int hp, Tipo tipo){
	Npc novo = self->item;
	novo->hp = hp;
	novo->id = id;	
	novo->tipo = tipo;
}

void printNpc(Object self, int position){
	if(self->type != 2) return;
	Npc npc = self->item;
	printf("====== Npc ======\n");
	if(!npc->tipo)
		printf("Raça: Dragão\n");
	if(npc->tipo == 1)
		printf("Raça: Monstro\n");
	if(npc->tipo == 2)
		printf("Raça: Demonio\n");
	printf("ID: %d\n" "HP: %d\n"
	, npc->id, npc->hp);	
	printf("Posição: %d\n\n", position);
}

void destroyNpc(Object objeto){
	free(objeto->item);
	free(objeto);
}
