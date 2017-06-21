#include "sudoku.h"
#define FALSE 0
#define TRUE 1
int sudoku[9][9]; /*= {0,0,0, 0,0,0, 0,1,0,
                    4,0,0, 0,0,0, 0,0,0,
                    0,2,0, 0,0,0, 0,0,0,

                    0,0,0, 0,5,0, 4,0,7,
                    0,0,8, 0,0,0, 3,0,0,
                    0,0,1, 0,9,0, 0,0,0,

                    3,0,0, 4,0,0, 2,0,0,
                    0,5,0, 1,0,0, 0,0,0,
                    0,0,0, 8,0,6, 0,0,0};*/
int sudoku2[9][9];
// funcao para iniciar o jogo
void jogarSudoku()
{
  int n = 0, n2 = 0, num = 1, i, j, cont = 0, k = 0;
  int p1[81], p2[81];
  int total = 0;
  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      if (sudoku2[i][j] != 0)
      {
        p1[k] = i;
        p2[k] = j;
        k++;
      }
    }

  }
  // loop para receber as coordenadas
  while (TRUE)
  {
    printf("Informe as coordenadas\n");
    scanf("%d", &n);
    scanf("%d", &n2);
    // saber se ja existe na posição incial
    if (n >= 1  && n <= 9 && n2 >= 1  && n2 <= 9)
    {
      cont = 0;
      for (i = 0; i < k ; i++)
      {
        if (n-1 == p1[i] && n2-1 == p2[i])
          cont = 1;
      }

      // caso não esteja
      if (cont != 1)
      {
        printf("Informe o número\n");
        scanf("%d", &num);
        if (num >= 1 && num <=9)
          sudoku2[n-1][n2-1] = num;
        else
          printf("Número inválido\n");
      }
      else
      {
        printf("Célula do Sudoku\n");
      }

    }
    else if (n == 0 && n2 == 0)
    {
        break;
    }
    else
    {
      printf("Coordenada inválida\n");
    }

    // chama a funcao para imprimir a matriz alterada ou não
    printSudoku2();
  }
  if (n == 0 && n2 == 0);
  {
    verificaSudoku();
  }

}
// preenche o sudoku do arquivo sudoku.txt
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
  //srand( (unsigned)time(NULL) );
  int x = 49151;//(rand()%50);
  //printf("%d\n", x);
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
// funcao para preencher a matriz do usuario
void geraMatrizUsuario()
{
  int i, j;
  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      sudoku2[i][j] = sudoku[i][j];
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
		for (j = 0; j < 9; j++)
    {
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

void printSudoku2()
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
			if (sudoku2[i][j] == 0)
				printf("|     |");
			else
				printf("|  %i  |",sudoku2[i][j]);
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

void verificaSudoku()
{
  int acertouMiserave = TRUE;
  int i, j;

  for (i = 0; i < 9; i++)
    for (j = 0; j < 9; j++)
      if(sudoku[i][j] != sudoku2[i][j])
        acertouMiserave = FALSE;

  if (acertouMiserave)
    printf("Acertou Miserave\n");
  else
    printf("Errou Miserave\n");
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
