#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10

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

int buscaBinaria(int vetor[], int inicio, int fim, int alvo){
	int flag = (inicio + fim) / 2;
	if(vetor[flag] == alvo)
		return flag;
	if(inicio >= fim)
		return -1;
	if(alvo > vetor[flag])	
		return buscaBinaria(vetor, flag + 1, fim, alvo);
	return buscaBinaria(vetor, inicio, flag - 1, alvo);
}

int main(){
	srand(time(NULL));
	int vetor[N];
	gerarValores(vetor, N);
	ordenarValores(vetor,N);
	printarValores(vetor, N);
	printf("Maior valor: %d\n", maiorValor(vetor, N));
	printf("Soma dos valores: %d\n", somaVetor(vetor, N));
	int alvo;
	printf("Digite um número: ");
	scanf(" %d", &alvo);
	printf("Posição do número usando busca linear: %d\n", 
	buscaLinear(vetor, N, alvo));
	printf("Posição do número usando busca binária: %d\n", buscaBinaria(vetor, 0, N, alvo));
	return 0;
}

