#define new(Type) new_##Type()

typedef enum{
	ARCO, ESPADA, LANCA,
}Equipamento;

typedef struct _Arma{
	int dano;
	int id;
	Equipamento equipamento;
}_Arma;

typedef _Arma* Arma;

Object new_Arma(){
	Object novo = new(Object);
	novo->type = ARMA;
	novo->item = malloc(sizeof(_Arma));
	return novo;
}

void setArma(Object self, int dano, int id, Equipamento equipamento){
	Arma novo = self->item;
	novo->dano = dano;
	novo->equipamento = equipamento;
	novo->id = id;
}

void printArma(Object self){
	Arma arma = self->item;
	if(self->type != ARMA) return;
	if(!arma->equipamento)
		printf("Arco\n");
	if(arma->equipamento == 1)
		printf("Espada\n");
	if(arma->equipamento == 2)
		printf("Lança\n");
	printf("Dano: %d\n" "ID: %d\n\n", arma->dano, arma->id);
}

