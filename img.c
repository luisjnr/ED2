#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "img.h"

int interface(){
	int opc;
	printf("1 - Baixar Imagem\n" "2 - Excluir Imagem\n"
	"3 - Criar Container\n" "4 - Interromper Container\n"
	"5 - Iniciar Container\n" "6 - Excluir Container\n" 
	"7 - Imagens Baixadas\n" "8 - Lista de Containers\n");
	int valido = scanf(" %d", &opc);
	while(getchar() != '\n');
	if(valido != 1)
		return -1;
	return opc;	
}

void baixarImagem(Body list){
	char type[1000];
	int size = 100 + rand() % 900;
	printf("====== Baixando Nova Imagem ======\n\n" "Tipo: ");
	scanf(" %s", type);
	new_imagem(list, type, size);
}

void criarContainer(Body list){
	if(!list->head){
		alert("Nenhuma imagem foi baixada.\n\n");
		return;
	}
	int id;				
	printf("====== Novo Container ======\n\n");
	listarImagem(list);
	printf("Digite o id da imagem: ");
	scanf(" %d", &id);
	new_container(list, id);
}

int main(){
	srand(time(NULL));
	Body list = new_list();
	do{
		switch (interface()){
			case 1: baixarImagem(list);
				break;
			case 2: excluirImagem(list);
				break;
			case 3: criarContainer(list);
				break;
			case 4: interromperContainer(list);
				break;
			case 5: iniciarContainer(list);
				break;
			case 6: excluirContainer(list);
				break;
			case 7: listarImagem(list);
				break;
			case 8: listarContainer(list);
				break;
			default: alert("Erro!\nOpção não existe.\nTente Novamente...\n\n");
		}
		
	} while (1);
}

