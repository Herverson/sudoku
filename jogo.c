#include "sudoku.h"

int sudoku[9][9] = {0,0,0, 0,0,0, 0,1,0,
                    4,0,0, 0,0,0, 0,0,0,
                    0,2,0, 0,0,0, 0,0,0,

                    0,0,0, 0,5,0, 4,0,7,
                    0,0,8, 0,0,0, 3,0,0,
                    0,0,1, 0,9,0, 0,0,0,

                    3,0,0, 4,0,0, 2,0,0,
                    0,5,0, 1,0,0, 0,0,0,
                    0,0,0, 8,0,6, 0,0,0};

/* funcao imprime o Sudoku*/
void printSudoku()
{
  printf("______________________________________\n");
  for (int i = 0 ; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
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
}

// funcao para solucionar o sudoku
int soluSudoku(int x, int y)
{
  int num = 1;
  int auxx = 0, auxy = 0;
  // caso a celula preenchida
  if (sudoku[x][y] != 0 )
  {
    if (x == 8 && y == 8)
    {
      return 1;
    }
    // caso a linha tenha terminado
    if (x < 8)
    {
      //incrementa para proxima linha
      x++;
    }
    // caso contrario
    else
    {
      // linha recebe 0
      x = 0;
      // incrementa coluna
      y++;
    }
    if (soluSudoku(x, y))
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  // caso a celula esteja vazia
  if (sudoku[x][y] == 0)
  {
    // preenche a celula com um numero entre 1 ate 9
    while (num < 10)
    {
    // não pode estar na mesma linha, mesma coluna e no mesmo quadrado
      if (!mesmoQuadrado(x, y, num) && !mesmaLinha(x, y, num) && !mesmaColuna(x, y, num))
      {
        sudoku[x][y] = num;
        if (x == 8 && y == 8)
        {
          return 1;
        }
        // caso a linha tenha terminado
        if (x < 8)
        {
          //incrementa para proxima linha
          auxx = x + 1;
        }
        // caso contrario
        else
        {
          // auxiliar da linha recebe 0
          auxx = 0;
          // auxiliar da coluna rebece o incremento da coluna
          auxy = y + 1;
        }
        if (soluSudoku(auxx, auxy))
        {
          return 1;
        }
      }
      num++;
    }
    sudoku[x][y] = 0;
    return 0;
  }
}
// funcao para saber se o numero está na mesma coluna
int mesmaColuna(int x, int y, int num)
{
  for (int i = 0; i < 9; i++)
  {
    if (sudoku[x][i] == num)
    {
      return 1;
    }
  }
  return 0;
}
// funcao para saber se o numero está na mesma linha
int mesmaLinha(int x, int y, int num)
{
  for (int i = 0; i < 9; i++)
  {
    if (sudoku[i][y] == num)
    {
      return 1;
    }
  }
  return 0;
}
// funcao para saber se o numero está no mesmo quadrado
int mesmoQuadrado(int x, int y, int num)
{
  // condicao da posição do numero no quadrado
  if (x < 3)
  {
    x = 0;
  }
  else if (x < 6)
  {
    x = 3;
  }
  else
  {
    x = 6;
  }
  // condicao da posição do numero no quadrado
  if (y < 3)
  {
    y = 0;
  }
  else if (y < 6)
  {
    y = 3;
  }
  else
  {
    y = 6;
  }
  for (int i = x; i < x + 3; i++)
  {
    for (int j = y; j < y + 3; j++)
    {
      if (sudoku[i][j] == num)
      {
        return 1;
      }
    }
  }
  return 0;
}
