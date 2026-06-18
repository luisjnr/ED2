#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

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
	switch (interface("1 - Novo Player\n2 - Nova Arma\n3 - Novo NPC\n")){
		case 1: list->enqueue(list, new(Player, "Luis Junior Lenda", 19, 100, ELFO));
			break;
		case 2: list->enqueue(list, new(Npc, 10, 10000, DRAGAO));
			break;
		case 3: list->enqueue(list, new(Arma, 19, 22, ESPADA));
			break;
		default: printf("Erro!\nTente Novamente...\n");
	}
}

void menuPrint(List list){
	switch (interface("1 - Print Players\n2 - Print Armas\n3 - Print NPCs\n" "4 - Print Lista\n")){
		case 1: list->print(list, printPlayer);
			break;
		case 2: list->print(list, printArma);
			break;
		case 3: list->print(list, printNpc);
			break;
		case 4: list->print(list, print_object);
			break;
		default: printf("Erro!\nTente Novamente...\n");
	}	
}

void menuBonusPlayer(List list){
	switch (interface("1 - Humano\n2 - Ogro\n3 - Elfo\n4 - Goblin\n")){
		case 1: list->bonus(list, new(Pbonus, 100, HUMANO), playerBonus);
			break;
		case 2: list->bonus(list, new(Pbonus, 30, OGRO), playerBonus);
			break;
		case 3: list->bonus(list, new(Pbonus, 50, ELFO), playerBonus);
			break;
		case 4: list->bonus(list, new(Pbonus, 80, GOBLIN), playerBonus);
			break;
		default: printf("Erro!\nTente Novamente...\n");
	}	
}

void menuDelete(List list){
	switch (interface("1 - Excluir Item Selecionado\n2 - Excluir Lista\n")){
		case 1: list->del(list, 0);
			break;
		case 2: list->clear(list);
			break;
		default: printf("Erro!\nTente Novamente...\n");
	}
}

void menu(List list){
	do{
		switch (interface("1 - Set Item\n2 - Print Item\n3 - Set Bônus\n4 - Excluir Item\n")){
			case 1: menuSet(list);
				break;
			case 2: menuPrint(list);
				break;
			case 3: menuBonusPlayer(list);
				break;
			case 4: menuDelete(list);
				break;
			default: printf("Erro!\nTente Novamente...\n");
		}
		
	} while (1);
}
