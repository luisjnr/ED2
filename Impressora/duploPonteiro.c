#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "duploPonteiro.h"

int interface(){
	int opc;
	printf("1 - Adicionar Arquivo\n" "2 - Fila de Impressão\n"
	"3 - Imprimir\n" "4 - Excluir da Fila\n" "5 - Mudar Prioridade\n");
	scanf(" %d", &opc);
	while(getchar() != '\n');
	system("clear");
	return opc;
}

void cadastrarDocument(Body list){
	char nome[1000];
	int paginas, tamanho;
	printf("===== NEW ARQUIVO =====\n\n" 
	"Nome: ");
	scanf(" %[^\n]s", nome);
	paginas = 1 + rand() % 50;
	tamanho = 100 + rand() % 900;
	return new_Document(list, nome, paginas, tamanho);
}

int main(){
	srand(time(NULL));
	Body list = new_List();
	do{
		switch (interface()){
			case 1: cadastrarDocument(list);
				alert("Adição concluída!\n");
				break;
				
			case 2: lista_Document(list);
				break;
				
			case 3: imprimir_Document(list);
				break;
				
			case 4: deletar_Document(list); 
				break;
				
			case 5: priorizar_Document(list);
				break;
				
			default: alert("Erro!\nOpção não existe.\nTente novamente...\n\n");
		}
	} while (1);
	
}
