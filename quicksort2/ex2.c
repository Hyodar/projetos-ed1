#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*Troca dois elementos {i,j} de posição.*/
void Swap (int *A, int i, int j) {
  int aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

/*Imprime o vetor:*/
void Imprimir (int *A, int tamanho) {
  int i;
  printf("Vetor:\n");
  for (i = 0; i < tamanho; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
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

/*Função particione do Quick-Sort.*/
int Particione (int A[], int l, int r) {
   int pivo = A[r];
   int i = l - 1;
   int j;
   for (j = l; j <= r - 1; j++) {
      if (A[j] <= pivo) {
         i += 1;
         Swap (A, i, j);
      }
   }
   Swap (A, i+1, r);
   return i + 1;
}

/*Quick-Sort.*/
void QuickSort (int A[], int l, int r) {
   if (l < r) {
      int pivo = Particione_Aleatorio (A, l, r);
      QuickSort (A, l, pivo-1);
      QuickSort (A, pivo+1, r); 
   }
}

int Particione_Aleatorio(int A[], int e, int d) {
	int s = rand()%(d-e+1) + e;

	if(s < e || s > d) {
		printf("jsjshdbdbsn\n");
	}

	int aux = A[s];
	A[s] = A[d];
	A[d] = aux;

	int pivo = A[d];
  	 int i = e - 1;
  	 int j;
 	  for (j = e; j <= d - 1; j++) {
  	    if (A[j] <= pivo) {
  	       i += 1;
  	       Swap (A, i, j);
  	    }
  	 }
 	  Swap (A, i+1, d);
 	  return i + 1;
}

int quickfind(int v[], int start, int end, int i) {
	if(start <= end) {
		int pivot = Particione_Aleatorio(v, start, end);
		if(pivot < i) {
			return quickfind(v, pivot + 1, end, i); 
		} else if(pivot > i) {
			return quickfind(v, start, pivot-1, i);
		} else {
			return v[pivot];
		}
	}
}


/*Função principal.*/
int main () {
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int i;
   int tamanho = 20;
   int *v = (int *)malloc(tamanho * sizeof(int));
   for (i = 0; i < tamanho; i++) {
      v[i] = rand() % (tamanho+1); /*aleatório*/
      //v[i] = i; /*crescente*/
      //v[i] = tamanho - i; /*decrescente*/
   }
   Imprimir (v, tamanho);
   start = clock();
   QuickSort (v, 0, tamanho-1);
   printf("%d\n", quickfind(v, 0, tamanho-1, 3));
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);
   if (!Verifica_Ordenacao(v, tamanho)) {
      printf("Erro: a ordenação não está correta!\n");
   } 
   Imprimir (v, tamanho);
   free (v);
   return 0;
}

