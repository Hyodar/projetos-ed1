
#include <stdio.h>
#include <stdlib.h>

/*
 * Para isso, poderia somente ser dispensada a última iteração
 * do CountingSort, que já gera a quantidade de números em cada
 * intervalo. Com isso, seria somente necessário pré-processar
 * esse vetor e retornar contagem[b] - contagem[a-1], buscando
 * o intervalo [a, b]. Para evitar acessos errados de memória,
 * os valores a e b devem ser certamente menores ou iguais a k,
 * além de a > 0 e != 0 e b > 0. Para isso, foram usadas 
 * checagens adicionais. Além disso, supõe-se que b >= a, o que
 * não foi feito, pois considerando o intervalo do enunciado,
 * matematicamente essa condição deve ser satisfeita por padrão.
 */

int* processCount(int a[], int n, int k) {

	int* c = (int*) malloc((k+1) * sizeof(int));

	for(int i = 0; i <= k; i++) c[i] = 0;
	for(int j = 0; j < n; j++) c[a[j]] = c[a[j]] + 1;
	for(int i = 1; i <= k; i++) c[i] = c[i] + c[i-1];

	return c;
}

int countInterval(int* count, int a, int b, int k) {
	a = (a > k)? k : a;
	b = (b > k)? k : b;
	a = (a < 0)? 0 : a;
	b = (b < 0)? 0 : b;

	if(a != 0) return count[b] - count[a - 1];
	return count[b];
}

// ----------------------------------------------------------------

void print(int a[], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');
}

int main() {

	int n;
	printf("Digite a quantidade de elementos: ");
	scanf("%d", &n);

	int* a = (int*) malloc(n * sizeof(int));

	int lim = 100;
	for(int i = 0; i < n; i++) {
		a[i] = rand() % lim;
	}

	print(a, n);
	int* count = processCount(a, n, lim);

	int k1 = 1;
	int k2 = 1;

	for(;;) {
		scanf("%d %d", &k1, &k2);
		printf("Quantidade de inteiros entre %d e %d: %d\n", k1, k2, countInterval(count, k1, k2, lim));
	}

	free(count);

	return 0;
}
