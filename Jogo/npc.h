#define new(Type) new_##Type()

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

Object new_Npc(){
	Object novo = new(Object);
	novo->type = NPC;
	novo->item = malloc(sizeof(_Npc));
	novo->set = setNpc;
	novo->print = printNpc;
	return novo;
}

void setNpc(Object self, int id, int hp, Tipo tipo){
	Npc novo = self->item;
	novo->hp = hp;
	novo->id = id;	
	novo->tipo = tipo;
}

void printNpc(Object self){
	if(self->type != NPC) return;
	Npc npc = self->item;
	printf("====== Npc ======\n");
	if(!npc->tipo)
		printf("Raça: Dragão\n");
	if(npc->tipo == 1)
		printf("Raça: Monstro\n");
	if(npc->tipo == 2)
		printf("Raça: Demonio\n");
	printf("ID: %d\n" "HP: %d\n\n"
	, npc->id, npc->hp);	
}
