#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void gerarValores(int vetor[], int t){
	if(!t)
		return;
	vetor[0] = 1 + rand() % 10;	
	gerarValores(vetor + 1, t - 1);
}

void printarValores(int vetor[], int t){
	if(!t)
		return;
	printf("%d\n", vetor[0]);		
	printarValores(vetor + 1, t - 1);
}

int maiorValor(int vetor[], int t){
	if(t==1)
		return vetor[0];
	int maior = maiorValor(vetor + 1, t - 1);
	if(vetor[0] > maior)
		maior = vetor[0];
	return maior;
}

int somaVetor(int vetor[], int t){
	if(t==1)
		return vetor[0];
	return vetor[0] + somaVetor(vetor + 1, t - 1);
}

void ordenarValores(int vetor[], int t){
	for (int i = 0; i < t; i++)
		for (int j = 0; j < t - i - 1; j++)
			if(vetor[j] > vetor[j+1]){
				int troca = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = troca;
			}
}		

int buscaLinear(int vetor[], int t, int alvo){
	if(!t)
		return -1;
	if(vetor[t-1] == alvo)
		return t-1;
	return buscaLinear(vetor, t-1, alvo);
}

int main(){
	srand(time(NULL));
	int vetor[10];
	gerarValores(vetor, 10);
	ordenarValores(vetor,10);
	printarValores(vetor, 10);
	printf("Maior valor: %d\n", maiorValor(vetor, 10));
	printf("Soma dos valores: %d\n", somaVetor(vetor, 10));
	int alvo;
	printf("Digite um número: ");
	scanf(" %d", &alvo);
	printf("Posição do número usando busca linear: %d\n", 
	buscaLinear(vetor, 10, alvo));
	return 0;
}

