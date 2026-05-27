#define new(Type) new_##Type()

int interface(char frase[]){
	int opc, verificar;
	printf("%s", frase);
	verificar = scanf(" %d", &opc);
	while(getchar() != '\n');
	if(verificar != 1)
		return -1;
	return opc;
}

void menuSet(List list){
	Object novo;
	switch (interface("1 - Novo Player\n2 - Nova Arma\n3 - Novo NPC\n")){
		case 1: novo = new(Player);
			setPlayer(novo, "Luis Junior Lenda", 19, 100, ELFO);
			list_Enqueue(list, novo);
			break;
		case 2: novo = new(Arma);
			setArma(novo, 12, 19, ESPADA);
			list_Enqueue(list, novo);
			break;
		case 3: novo = new(Npc);
			setNpc(novo, 19, 10000, DRAGAO);
			list_Enqueue(list, novo);
			break;
		default: printf("Erro!\nTente Novamente...\n");
	}
}

void menuPrint(List list){
	switch (interface("1 - Print Players\n2 - Print Armas\n3 - Print NPCs\n")){
		case 1: list_Print(list, printPlayer, "PLAYERS");
			break;
		case 2: list_Print(list, printArma, "ARMAS");
			break;
		case 3: list_Print(list, printNpc, "NPCs");
			break;
		default: printf("Erro!\nTente Novamente...\n");
	}	
}

void menuBonus(List list){
	Object novo;
	switch (interface("1 - Humano\n2 - Ogro\n3 - Elfo\n4 - Goblin\n")){
		case 1: novo = new(Pbonus);
			set_Pbonus(novo, 100, HUMANO);
			list_Bonus(list, novo, playerBonus);
			destroy(novo);
			break;
		case 2: novo = new(Pbonus);
			set_Pbonus(novo, 30, OGRO);
			list_Bonus(list, novo, playerBonus);
			destroy(novo);
			break;
		case 3: novo = new(Pbonus);
			set_Pbonus(novo, 50, ELFO);
			list_Bonus(list, novo, playerBonus);
			destroy(novo);
			break;
		case 4:novo = new(Pbonus);
			set_Pbonus(novo, 70, GOBLIN);
			list_Bonus(list, novo, playerBonus);
			destroy(novo);
			break;
		default: printf("Erro!\nTente Novamente...\n");
	}	
}

void menu(List list){
	do{
		switch (interface("1 - Set Item\n2 - Print Item\n3 - Set Bônus\n")){
			case 1: menuSet(list);
				break;
			case 2: menuPrint(list);
				break;
			case 3: menuBonus(list);
				break;
			default: printf("Erro!\nTente Novamente...\n");
		}
		
	} while (1);
}
