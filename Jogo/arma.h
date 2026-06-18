#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

typedef enum{
	ARCO, ESPADA, LANCA,
}Equipamento;

typedef struct _Arma{
	int dano;
	int id;
	Equipamento equipamento;
}_Arma;

typedef _Arma* Arma;

void setArma();
void printArma();
void destroyArma();

Object new_Arma(int id, int dano, Equipamento equipamento){
	Object novo = new(Object);
	novo->type = 1;
	novo->item = malloc(sizeof(_Arma));
	novo->set = setArma;
	novo->print = printArma;
	novo->destroy = destroyArma;
	setArma(novo, dano, id, equipamento);
	return novo;
}

void setArma(Object self, int id, int dano, Equipamento equipamento){
	Arma novo = self->item;
	novo->dano = dano;
	novo->equipamento = equipamento;
	novo->id = id;
}

void printArma(Object self, int position){
	Arma arma = self->item;
	if(self->type != 1) return;
	printf("====== Arma ======\n");
	if(!arma->equipamento)
		printf("Arco\n");
	if(arma->equipamento == 1)
		printf("Espada\n");
	if(arma->equipamento == 2)
		printf("Lança\n");
	printf("Dano: %d\n" "ID: %d\n", arma->dano, arma->id);
	printf("Posição: %d\n\n", position);
}

void destroyArma(Object objeto){
	free(objeto->item);
	free(objeto);
}

