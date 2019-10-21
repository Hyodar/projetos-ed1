#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particione(int* v, int l, int r) {
	int x = v[r];
	int i = l-1;

	for(int j = l; j < r; j++) {
		if(v[j] <= x) {
			i++;
			int aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
	}
	int aux = v[i+1];
	v[i+1] = v[r];
	v[r] = aux;
	return i+1;
}



void QuickSort(int* v, int l, int r) {
	if(l < r) {
		int q = particione(v, l, r);
		QuickSort(v, l, q-1);
		QuickSort(v, q+1, r);
	}
}

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (A[i] > A[i+1]) {
       return 0;
    }
  }
  return 1;
}

void Imprimir (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", A[i]);
  } 
  printf ("\n");
}

void aleatorio(int* v, int len) {
	for(int i = 0; i < len; i++) {
		v[i] = rand() % 100;
	}
}

int menorIntervalo(int* v, int len) {
	QuickSort(v, 0, len-1);

	int men = v[1] - v[0];

	for(int i = 0; i < len-1; i++) {
		int test = v[i+1] - v[i];
		if(test < men) men = test;
	}

	return men;
}

/*Função principal.*/

int main (int argc, char *argv[]) {
   srand(time(NULL));

   int tamanho = 10;

	int *v = (int *)malloc(tamanho * sizeof(int));
	aleatorio(v, tamanho);
	Imprimir(v, tamanho);
	int q = menorIntervalo(v, tamanho);
	printf("%d\n", q);
	free(v);

   return 0;
}
