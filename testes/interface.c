#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n = 0, n2 = 0, num = 1, i, j, cont = 0, k = 0;
  int p1[81], p2[81];
  int total = 0;
  int sudoku[9][9]={0,0,0, 0,0,0, 0,1,0,
                    4,0,0, 0,0,0, 0,0,0,
                    0,2,0, 0,0,0, 0,0,0,

                    0,0,0, 0,5,0, 4,0,7,
                    0,0,8, 0,0,0, 3,0,0,
                    0,0,1, 0,9,0, 0,0,0,

                    3,0,0, 4,0,0, 2,0,0,
                    0,5,0, 1,0,0, 0,0,0,
                    0,0,0, 8,0,6, 0,0,0};
  printf("______________________________________\n");
  for (i = 0 ; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
        if(j == 8 && i == 8 )
          {
              printf(" %d ", sudoku[i][j]);
              printf("|");
          }
          else
          {
               printf(" %d ", sudoku[i][j]);
               printf("|");
          }

           if (((j + 1) % 3) == 0 && j < 8)
           {
              printf("|");
           }
    }
    printf("\n");
       if (((i + 1) % 3) == 0)
       {
           printf("---------------------------------------\n");
       }
  }
  printf("\n\n");
  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      if (sudoku[i][j] != 0)
      {
        p1[k] = i;
        p2[k] = j;
        k++;
      }
    }

  }
  // loop para receber as coordenadas
  while (num != 0)
  {
    printf("Informe as coordenadas\n");
    scanf("%d", &n);
    scanf("%d", &n2);
    // saber se ja existe na posição incial
    cont = 0;
    for (i = 0; i < k ; i++)
    {
      if (n == p1[i] && n2 == p2[i])
        cont = 1;
    }
    // caso não esteja
    if (cont != 1)
    {
      printf("Informe o número\n");
      scanf("%d", &num);
      if (num >= 1 && num <=9)
        sudoku[n][n2] = num;
      else
        printf("Número inválido\n");
    }
    else
    {
      printf("codernada inválida\n");
    }

  }

  printf("______________________________________\n");
  for (i = 0 ; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
        if(j == 8 && i == 8 )
          {
              printf(" %d ", sudoku[i][j]);
              printf("|");
          }
          else
          {
               printf(" %d ", sudoku[i][j]);
               printf("|");
          }

           if (((j + 1) % 3) == 0 && j < 8)
           {
              printf("|");
           }
    }
    printf("\n");
       if (((i + 1) % 3) == 0)
       {
           printf("---------------------------------------\n");
       }
  }
  printf("\n\n");
  return 0;

}
