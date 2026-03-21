#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input(char frase[], int *n){
	printf("%s", frase);
	scanf(" %d", n);
	system("clear");
	if(*n > 1000){
		printf("Máximo suportado: 1000\nTente novamente...\n");
		input(frase, n);
	}
}

void inicializar(int memoria[], int n){
	if(!n)
		return;
	inicializar(memoria + 1, n - 1);
	memoria[0] = 0;
}

int interface(){
	printf("1 - Gerar novo processo\n" "2 - Excluir processo\n"
	"3 - Listar processos\n" "4 - Desligar computador\n");
	int opc;
	scanf(" %d", &opc);
	while(getchar() != '\n');
	system("clear");
	return opc;
}

void gerarProcesso(int memoria[], int n, int *contKernel, int *contUsuario){
	int max;
	do{
		input("Quantos processos devem ser gerador? ", &max);
		if(max + (*contKernel + *contUsuario) > n)
			printf("Número máximo atingido\nTente novamente...\n" 
			"Espaços para processos disponíveis: %d\n\n", n - (*contKernel + *contUsuario));
		else break;
	} while (1);
	do{
		if(!max) 
			break;
		int processo = 1 + rand() % n;
		if(*contKernel == n/2)
			processo = 1;
		if(*contUsuario == n/2)
			processo = 2;
		int ponto = processo;
		if(!(processo % 2)){
			if((*contKernel) < n/2){
				do{
					if(!memoria[processo - 1]){
						memoria[processo - 1] = processo;
						(*contKernel)++;
						break;
					}
					else
						processo += 2;
					if(processo > n){
						processo = ponto;
						do{
							if(!memoria[processo - 1] && processo <= n){
								memoria[processo - 1] = processo;
								(*contKernel)++;
								break;
							}
							else
								processo -= 2;
							if(processo < 2)
								break;
						} while (1);
						break;
					}
				} while (1);

			}	
		}
		else{
			if((*contUsuario) < n/2){
				do{
					if(!memoria[processo - 1]){
						memoria[processo - 1] = processo;
						(*contUsuario)++;
						break;
					}
					else
						processo += 2;
					if(processo > n){
						processo = ponto;
						do{
							if(!memoria[processo - 1] && processo <= n){
								memoria[processo - 1] = processo;
								(*contUsuario)++;
								break;
							}
							else
								processo -= 2;
							if(processo < 1)
								break;
						} while (1);
						break;
					}
				} while (1);

			}	
		}
		max--;
	} while (1);
	
}

void listarKernel(int memoria[], int n);

void listarUsuario(int memoria[], int n){
	if(!n)
		return;
	if(!memoria[0])
		printf("[NULL]\n");
	else
		printf("[%04d]\n", memoria[0]);
	listarKernel(memoria + 1, n - 1);	
}

void listarKernel(int memoria[], int n){
	if(!n)
		return;
	if(!memoria[0])
		printf("[NULL]\t\t");
	else
		printf("[%04d]\t\t", memoria[0]);
	listarUsuario(memoria + 1, n - 1);
}

void terminarProcesso(int memoria[], int *contKernel, int *contUsuario){
	int cod;
	do{
		input("Digite o código do processo para finalizar: ", &cod);
		if(!memoria[cod - 1])
			printf("Processo não está sendo executado!\nTente novamente...\n");
		else break;
	} while (1);
	memoria[cod - 1] = 0;
	if(!(cod % 2))
		(*contKernel)--;
	else
		(*contUsuario)--;
}

void enter(char frase[]){
	printf("%s ", frase);
	getchar();
	while(getchar() != '\n');
	system("clear");
}

int main(){
	srand(time(NULL));
	int contKernel = 0;
	int contUsuario = 0;
	int n;
	input("Quantos processos serão suportados? ", &n);
	int memoria[n];
	inicializar(memoria, n);
	do{
		switch (interface())
		{
			case 1: gerarProcesso(memoria, n, &contKernel, &contUsuario);
				enter("Processos iniciados\nPressione 'ENTER' para prosseguir");
				break;
			case 2: printf("===== Processos =====\n\n" 
				"Processos em andamento: %d\n\n" "Usuário\t\tKernel\n", contKernel + contUsuario);  
				listarKernel(memoria, n); 
				terminarProcesso(memoria, &contKernel, &contUsuario);
				enter("Processo finalizado\nPressione 'ENTER' para prosseguir");
				break;
			case 3:	printf("===== Processos =====\n\n" 
				"Processos em andamento: %d\n\n" "Usuário\t\tKernel\n", contKernel + contUsuario); 
				listarKernel(memoria, n);
				enter("Pressione 'ENTER' para prosseguir");
				break;
			case 4: system("clear");
				printf("Código finalizado!");
				return 0;
			default:
		}
	} while (1);
	
	return 0;
}
