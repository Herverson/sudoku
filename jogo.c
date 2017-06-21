#include "sudoku.h"

int sudoku[9][9]; /*= {0,0,0, 0,0,0, 0,1,0,
                    4,0,0, 0,0,0, 0,0,0,
                    0,2,0, 0,0,0, 0,0,0,

                    0,0,0, 0,5,0, 4,0,7,
                    0,0,8, 0,0,0, 3,0,0,
                    0,0,1, 0,9,0, 0,0,0,

                    3,0,0, 4,0,0, 2,0,0,
                    0,5,0, 1,0,0, 0,0,0,
                    0,0,0, 8,0,6, 0,0,0};*/
// funcao
void geraMatriz()
{

  int c;
  int n = 0;
  int i,j;
  int vetor[81];
  FILE *fp;

  fp = fopen("sudoku.txt","r");
  if(fp == NULL)
  {
    printf("Não foi possivel abrir arquivo\n");
    return;
  }
  srand( (unsigned)time(NULL) );
  int x = (rand()%50);
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
      sudoku[i][j] = vetor[k];
      k++;
    }
  }
}

/* funcao imprime o Sudoku*/
void printSudoku()
{
  int i, j;
  //system("clear");

	for (i = 0; i< 9; i++)
  {
		//printf("\n");
		for (j = 0; j < 9; j++){
			if (j == 3 || j == 6)
				printf(" ");
			if (i == 0 || i == 3 || i == 6)
      {
				if (j == 0)
					printf(" _____  ");
				else
					printf("_____  ");
			}
		}
		printf("\n");
		for (j = 0; j < 9; j++)
    {
			if (j == 3 || j == 6)
				printf(" ");
			printf("|     |");
		}
		printf("\n");
    for (j = 0; j < 9; j++)
    {
			if (j == 3 || j == 6)
				printf(" ");
			if (sudoku[i][j] == 0)
				printf("|     |");
			else
				printf("|  %i  |",sudoku[i][j]);
		}
		printf("\n");
		for (j = 0; j< 9; j++)
    {
			if (j == 3 || j == 6)
			printf(" ");
			printf("|_____|");
		}
		if (i == 2 || i == 5)
			printf("\n");
	}
printf("\n");
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
