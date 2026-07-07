#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"
#include "inteiro.h"
#include "list.h"
#include "hash.h"

enum{INTEIRO};

int main(){
	Hash hs = new(Hash, 12);
	
	hs->insert(hs, 80, new(Int, 1, INTEIRO));
	hs->insert(hs, 80, new(Int, 2, INTEIRO));
	hs->insert(hs, 30, new(Int, 3, INTEIRO));
	hs->insert(hs, 80, new(Int, 4, INTEIRO));
	hs->insert(hs, 80, new(Int, 5, INTEIRO));
	
	hs->del(hs, 80, 0);
	
	List lst = hs->search(hs, 30);
	
	printf("LISTA COD-80\n\n");
	
	hs->print(hs, 80);
	
	printf("\n\n\nLISTA COD-30\n\n");
	
	lst->print(lst);
	
	return 0;
}

