#include <stdio.h>
#include <stdlib.h>

int sudoku[9][9] ;
int sudoku2[9][9] ;/*= {0,9,8,0,0,5,0,6,0,6,0,0,9,0,0,0,0,3,0,0,3,6,0,7,9,0,1,3,0,
  7,0,0,0,4,1,0,0,0,0,0,1,0,0,0,0,0,6,1,0,0,0,8,0,2,5,0,4,2,0,6,1,0,0,7,0,0,0,0
  ,8,0,0,5,0,1,0,4,0,0,3,2,0};*/

int soluSudoku(int, int);
int mesmaColuna(int, int, int);
int mesmaLinha(int, int, int);
int mesmoQuadrado(int, int, int);
void geraMatriz();
void printSudoku();
void printSudoku2();
int main()
{

  //int x = 0, y = 0;
  geraMatriz();

  //printSudoku();
}
void geraMatriz()
{
  int i, j, k = 0; //x, l;
  int x = 0, y = 0;
  char c;
  int vetor[81];
  FILE *fp;
  //l = 0;
  //x = 5;
  i = 0;
  fp = fopen("facil.txt", "rt");
  while ((c = fgetc(fp)) != EOF)
  {
    //if (l == x)
    //{
    i = 0;
      do
      {
        vetor[i] = c - '0';
        i++;
        c = fgetc(fp);
      }while (c != '\n');

    //}
    //if (c == '\n')
    //    l++;
    //if (i == 81)
        k = 0;
        for (i = 0; i < 9; i++)
        {
          for (j = 0; j < 9; j++)
          {
            sudoku[i][j] = vetor[k];
            k++;
          }
        }
          for (i = 0; i < 9; i++)
          {
            for (j = 0; j < 9; j++)
            {
              sudoku2[i][j] = sudoku[i][j];
            }
          }
        printSudoku2();
        printf("\n");
        soluSudoku(x, y);
        printSudoku();
        printf("\n");

      }
  fclose(fp);
  // passa os valores do arquivo para a matriz

}
void printSudoku()
{
  int i, j;
  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      printf("%d", sudoku[i][j]);
    }
  }

}
void printSudoku2()
{
  int i, j;
  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      printf("%d", sudoku2[i][j]);
    }
  }

}
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
        // caso a linha não tenha terminado
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
