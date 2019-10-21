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
		v[i] = rand();
	}
}

void crescente(int* v, int len) {
	for(int i = 0; i < len; i++) {
		v[i] = i;
	}
}

void decrescente(int* v, int len) {
	for(int i = 0; i < len; i++) {
		v[i] = len - i;
	}
}

/*Função principal.*/

int main (int argc, char *argv[]) {
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));

   // Melhor: aleatorio
   // Pior: crescente
   //
   //	10000: 0.67 cresc, 0.42 dec, 0.00 aleatorio
   //	se for crescente, alem de fazer todas as com
   //	paracoes, faz todas as trocas possiveis. no caso decre
   //	scente, mesmo tambem sendo o pior pivo, faz
   //	menos trocas.

   int tamanho = 1;
   for(int i = 1; i <= 6; i++) {
	tamanho *= 10;
   	int *v = (int *)malloc(tamanho * sizeof(int));
	printf("%d: \n", tamanho);
	printf("crescente: \n");
	crescente(v, tamanho);
	//Imprimir(v, tamanho);
	start = clock();
	QuickSort(v, 0, tamanho-1);
	end = clock();
	elapsed_time = (end-start)/(double)CLOCKS_PER_SEC;
	printf("%.2f - ver: %d\n", elapsed_time, Verifica_Ordenacao(v, tamanho));
	printf("decrescente:\n");
	decrescente(v, tamanho);
	//Imprimir(v, tamanho);
	start = clock();
        QuickSort(v, 0, tamanho-1);                             end = clock();                                          elapsed_time = (end-start)/(double)CLOCKS_PER_SEC;                                                              printf("%.2f - ver: %d\n", elapsed_time, Verifica_Ordenacao(v, tamanho));
	printf("aleatorio:\n");                                 aleatorio(v, tamanho);
	//Imprimir(v, tamanho);
	start = clock();                                        QuickSort(v, 0, tamanho-1);
        end = clock();                                          elapsed_time = (end-start)/(double)CLOCKS_PER_SEC;                                                              printf("%.2f - ver: %d\n", elapsed_time, Verifica_Ordenacao(v, tamanho));
	free(v);
   }

   return 0;
}
