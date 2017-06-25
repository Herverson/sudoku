#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  FILE *fp;
  int vetor[6], i, j, pt = 4, aux;
  // abrir arquivo
  vetor[5] = pt;
  fp = fopen("top5.txt","rt");
  if(fp == NULL)
  {
    printf("Não foi possivel abrir arquivo\n");
    return 0;
  }
  // ler os dados e colocar na  matriz
  for (i = 0; i < 5; i++)
  {
    fscanf(fp, "%d", &vetor[i]);
  }
  // ordenar o TOP5
  for (i = 0; i < 6; i++)
  {
    for (j = i + 1; j < 6; j++)
    {
      if (vetor[i] > vetor[j])
      {
          aux = vetor[j];
          vetor[j] = vetor[i];
          vetor[i] = aux;
      }
    }
  }
  // modo escrita
  fp = fopen("top5.txt","w");
  for (i = 0; i < 5; i++)
  {
    fprintf(fp, "%d\n", vetor[i]);
  }
  return 0;
}
