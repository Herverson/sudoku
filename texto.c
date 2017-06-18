#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int c;
  int n = 0;
  int i,j;
  int vetor[81];
  int matriz[9][9];
  FILE *fp;

  fp = fopen("9.txt","r");
  if(fp == NULL)
  {
    printf("Não foi possivel abrir arquivo\n");
    return 1;
  }
  srand( (unsigned)time(NULL) );
  //int x = 1 + (rand()%50);
  //int x = 26327;
  int x = 0;
  printf("%d\n", x);
  i = 0;
  int c1 = 0;
  while ((c = fgetc(fp)) != EOF)
  {
    if (c1 == x)
    {
      do
      {
          switch (c)
          {
            case 48:
                  vetor[i] = 0;
            break;
            case 49:
                  vetor[i] = 1;
            break;
            case 50:
                  vetor[i] = 2;
            break;
            case 51:
                  vetor[i] = 3;
            break;
            case 52:
                  vetor[i] = 4;
            break;
            case 53:
                  vetor[i] = 5;
            break;
            case 54:
                  vetor[i] = 6;
            break;
            case 55:
                  vetor[i] = 7;
            break;
            case 56:
                  vetor[i] = 8;
            break;
            case 57:
                  vetor[i] = 9;
            break;
          }
        i++;
        c = fgetc(fp);
      }while (c != '\n');

    }
    if (c == '\n')
        c1++;	
    if (i == 81)
        break; 
   
	
}
  fclose(fp);

  int k = 0;
  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      matriz[i][j] = vetor[k];
      k++;
    }
  }
  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      printf(" %d ", matriz[i][j]);
    }
    printf("\n");
  }
  return 0;
}
