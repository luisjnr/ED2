#include <stdio.h>
#include <stdlib.h>

long long fibonacciRecursivo(int n){
	if(!n)
		return 0;
	if(n <= 2)
		return 1;
	return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

void iniciar(long long vet[], int n){
	if(!n)
		return;
	iniciar(vet + 1, n - 1);
	vet[0] = 0;
}

long long fibonacciDinamico(long long vet[], int n){
	if(!n)
		return 0;
	if(n <= 2)
		return 1;
	if(!vet[n - 1])	
		return vet[n - 1] = fibonacciDinamico(vet, n - 1) + fibonacciDinamico(vet, n - 2);
	return vet[n - 1];
}

int main(){
	int n;
	printf("Digite um número: ");
	scanf(" %d", &n);
	long long vet[n];
	iniciar(vet, n);
	printf("Fibonacci dinâmico: %lld\n", fibonacciDinamico(vet, n));
	printf("Fibonacci recursivo: %lld\n", fibonacciRecursivo(n));
	
	return 0;
}
