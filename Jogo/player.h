#define new(Type) new_##Type()

typedef enum{
	HUMANO, OGRO, ELFO, GOBLIN,	
}Raca;

typedef struct _Player{
	char* nome;
	Raca raca;
	int id;
	int hp;
}_Player;

typedef _Player* Player;

typedef struct BonusPlayer{
	int bonus;
	Raca raca;
	Player player;
}BonusPlayer;

typedef BonusPlayer* Pbonus;

void setPlayer();
void playerBonus();
void printPlayer();
void set_Pbonus();

Object new_Player(){
	Object novo = new(Object);
	novo->type = PLAYER;
	novo->item = malloc(sizeof(_Player));
	novo->print = printPlayer;
	novo->set = setPlayer;
	return novo;
}

void setPlayer(Object self, char* nome, int id, int hp, Raca raca){
	Player player = self->item;
	player->hp = hp;
	player->id = id;
	player->raca = raca;
	player->nome = malloc(strlen(nome) + 1);
	strcpy(player->nome, nome);
}

Object new_Pbonus(){
	Object novo = new(Object);
	novo->type = PLAYER;
	novo->item = malloc(sizeof(BonusPlayer));
	novo->set = set_Pbonus;
	return novo;
}

void set_Pbonus(Object self, int bonus, Raca raca){
	Pbonus novo = self->item;
	novo->bonus = bonus;
	novo->raca = raca;
}

void printPlayer(Object self){
	if(self->type != PLAYER) return;
	Player player = self->item;
	printf("====== Player ======\n" "Nome: %s\n" "ID: %d\n" "HP: %d\n"
	, player->nome, player->id, player->hp);
	if(!player->raca)
		printf("Raça: Humano\n\n");
	if(player->raca == 1)
		printf("Raça: Ogro\n\n");
	if(player->raca == 2)
		printf("Raça: Elfo\n\n");
	if(player->raca == 3)
		printf("Raça: Goblin\n\n");	
}

void playerBonus(Object self, Object info){
	Pbonus contexto = info->item;
	contexto->player = self->item;	
	if(contexto->player->raca != contexto->raca) return;
	contexto->player->hp += contexto->bonus;
}
