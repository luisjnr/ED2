#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"
#include "player.h"
#include "npc.h"
#include "arma.h"
#include "list.h"
#include "interface.h"

typedef enum{
	PLAYER, ARMA, NPC,
}TypeNode;

int main(){
	List list = new(List);
	menu(list);
	return 0;
}
