#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int interface(){
	int opc;
	printf("1 - Jogar\n" "2 - Desligar\n");
	scanf(" %d", &opc);
	while(getchar() != '\n');
	system("clear");
	return opc;
}

void processamento(char frase[], char sis[]){
	printf("%s", frase);
	system(sis);
}

void kernel(){
	processamento("Aguarde...\n", "sleep 2");
	system("clear");
	processamento("System call iniciada...\n", "sleep 2");
	system("clear");
	processamento("Salvando contexto...\n", "sleep 2");
	system("clear");
	processamento("Alterando para modo kernel...\n", "sleep 2");
	system("clear");
	processamento("===== MODO KERNEL =====\n\n", "sleep 1");
	processamento("Realizando rotinas...\n", "sleep 1");
	processamento("Rotinas finalizadas.\n", "sleep 1");
	processamento("Alterando para modo usuário...\n", "sleep 2");
	system("clear");
	processamento("===== MODO USUÁRIO =====\n\n", "sleep 1");
	processamento("Restaurando contextos...\n", "sleep 1");
	system("clear");
}

int primo(int n){
	if (n <= 1) return 0;
	for (int j = 2; j * j <= n; j++)
		if (n % j == 0 ){
				return 0;
			}
	return 1;
}

void jogoMatematico(){
	int cont = 0;
	
	for (int i = 0; i < 10; i++){
		printf("===== MODO USUÁRIO =====\n\n");
		int n1 = 1 + rand() % 100; 
		int n2 = 1 + rand() % 100;
		int resp;
		printf("%d/10\n", i + 1);
		printf("Quanto é %d + %d ?\n", n1, n2);
		system("sleep 1");
		if(primo(n1) || primo(n2)){
			system("clear");
			kernel();
			printf("===== MODO USUÁRIO =====\n\n");
			printf("%d/10\n", i + 1);
			printf("Quanto é %d + %d ?\n", n1, n2);
		}
		scanf(" %d", &resp);
		system("clear");
		resp == (n1 + n2) ? cont++ : cont;
	}
	
	printf("Acertos totais: %d\n", cont);
}

void desligando(){
	printf("Desligando aguarde...\n");
	system("sleep 3");
	system("clear");
	printf("Desligado.");
}

int main(){
	srand(time(NULL));
	do{
		switch (interface())
		{
			case 1: jogoMatematico();
				
				break;
				
			case 2: desligando();
			return 0;
				
				break;
			default: printf("Opção não existe!\nTEnte novamente...");			
		}	
	} while (1);
}

