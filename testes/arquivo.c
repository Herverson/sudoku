#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  FILE *fp;
  int vetor[5], i, j, vetor2[5];
  // abrir arquivo
  fp = fopen("sudoku.txt","rt");
  if(fp == NULL)
  {
    printf("Não foi possivel abrir arquivo\n");
    return 0;
  }
  // receber valores
  for (int i = 0; i < 5; i++)
  {
    scanf("%d", &vetor2[i]);
  }
  // ler os dados e colocar na  matriz
  for (i = 0; i < 5; i++)
  {
    fscanf(fp, "%d", &vetor[i]);
  }
  for (i = 0; i < 5; i++)
  {
    for (j = 0; j < 5; j++)
    {
      if (vetor2[i] < vetor[j])
      {
        aux = vetor[j];
        vetor[j] = vetor2[i];
        break;
      }
    }
  }
  for (i = 0; i < 5; i++)
  {
    printf("%d\n", vetor[i]);
  }
  fp = fopen("sudoku.txt","w");
  for (i = 0; i < 5; i++)
  {
    fprintf(fp, "%d\n", vetor[i]);
  }
  return 0;
}
