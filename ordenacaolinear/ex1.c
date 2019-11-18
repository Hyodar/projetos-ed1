
#include <stdio.h>
#include <stdlib.h>

void countingSort(int a[], int n, int b[], int k) {

	int* c = (int*) malloc((k+1) * sizeof(int));

	for(int i = 0; i <= k; i++) c[i] = 0;
	for(int j = 0; j < n; j++) c[a[j]] = c[a[j]] + 1;
	for(int i = 1; i <= k; i++) c[i] = c[i] + c[i-1];

	for(int j = n-1; j >= 0; j--) {
		b[c[a[j]] - 1] = a[j];
		--c[a[j]];
	}

	free(c);
}

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
	int* b = (int*) malloc(n * sizeof(int));

	int lim = 10000;
	for(int i = 0; i < n; i++) {
		a[i] = rand() % lim;
	}

	print(a, n);
	
	countingSort(a, n, b, lim - 1);

	print(b, n);
	return 0;

}
