#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  FILE *fp;
  int i, j, pt = 3, aux, n;
  // abrir arquivo
  fp = fopen("top5.txt","rt");
  if(fp == NULL)
  {
    fp = fopen("top5.txt","w");
    fprintf(fp, "%d\n", pt);
    return 0;
  }
  else
  {
    int vetor[6] = {0};
    i = 0;
    while (fscanf(fp, "%d", &vetor[i]) != EOF)
    {
      printf("%d\n", vetor[i]);
        i++;
    }
    printf("teste\n");
    vetor[i+1] = pt;

    n = i + 1;
    // ordenar o TOP5
    for (i = 0; i <= n; i++)
    {
      for (j = i + 1; j <= n; j++)
      {
        if (vetor[i] > vetor[j])
        {
            aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
        }
      }
    }
    // imprime
    for (i = 0; i <= n; i++)
    {
        printf("%d\n", vetor[i]);
    }
    // modo escrita
    fp = fopen("top5.txt","w");
    for (i = 0; i < 6; i++)
    {
        if (vetor[i] != 0)
            fprintf(fp, "%d\n", vetor[i]);
    }
  }
  fclose(fp);
  return 0;
}
