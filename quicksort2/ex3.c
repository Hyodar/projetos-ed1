#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Troca dois elementos {i,j} de posição.*/
void Swap (char **A, int i, int j) {
  char *aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (char **A, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (strcmp (A[i],A[i+1]) > 1) {
       return 0;
    }
  }
  return 1;
}

/*Quick-Sort.*/
void QuickSort (char **A, int l, int r) {
	if(l < r) {
		int pivot = Particione_Aleatorio(A, l, r);
		QuickSort(A, l, pivot-1);
		QuickSort(A, pivot+1, r);
	}
}

int Particione_Aleatorio(char** A, int e, int d) {
        int s = rand()%(d-e+1) + e;

        if(s < e || s > d) {                                            printf("jsjshdbdbsn\n");
        }

        char* aux = A[s];
        A[s] = A[d];
        A[d] = aux;

        char* pivo = A[d];
         int i = e - 1;
         int j;
          for (j = e; j <= d - 1; j++) {                            if (strcmp(A[j], pivo) <= 0) {
               i += 1;
               Swap (A, i, j);                                      }
         }
          Swap (A, i+1, d);                                       return i + 1;
}

/*Função para contar o número de linhas de um arquivo.*/
int conta_linhas (FILE *arq) {
  int linhas = 0;
  if (arq == NULL) {
    return linhas; 
  }
  while (!feof(arq)) {
    char c;
    fscanf(arq, "%c", &c);
    if (c == '\n') {
      linhas++;
    }
  }
  rewind(arq);
  return (linhas-1);
}

/*Função principal.*/
int main (int argc, char *argv[]) {
   srand(time(NULL));
 
   /*Abrindo o arquivo:*/
   FILE *arq = fopen("palavras.txt", "r"); //fopen(argv[1],"r");

   /*Contando o número de linhas do arquivo:*/
   int linhas = conta_linhas(arq);
   printf("O número de linhas do arquivo é: %d\n", linhas);
   
   /*Alocando memória para armazenar as palavras:*/
   char **palavras = (char **)malloc(linhas * sizeof(char *));
   int i;
   for (i = 0; i < linhas; i++) {
      palavras[i] = (char *)malloc(256 * sizeof(char));
   }
   
   /*Lendo as palavras do arquivos:*/
   i = 0;
   while (!feof(arq)) {
      fscanf(arq, "%s", palavras[i]);     
      i++;
   }

   /*Ordenando as palavras:*/
   clock_t start = clock();
   QuickSort (palavras, 0, linhas-1);
   clock_t end = clock();
   double elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);

   /*Imprimindo as palavras:*/
   for (i = 0; i < linhas; i++) {
      printf("%s\n", palavras[i]);
   }

   /*Verificando se a ordenação está correta:*/
   if (!Verifica_Ordenacao(palavras, linhas)) {
      printf("Erro: a ordenação não está correta!\n");
   }

   /*Liberando a memória:*/
   for (i = 0; i < linhas; i++) {
      free(palavras[i]);
   }
   free(palavras);
   fclose(arq);
   return 0;
}

