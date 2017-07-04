#include "sudoku.h"

int sudoku[9][9];
int sudoku2[9][9];
int modofacil = FALSE;
// funcao menu

void menu()
{
  int num;
  //do
  //{
      system("clear");
      printf("\033[34m");
      puts("\t\t\t\t┏━━━┳┓╋┏┳━━━┳━━━┳┓┏━┳┓╋┏┓");
      puts("\t\t\t\t┃┏━┓┃┃╋┃┣┓┏┓┃┏━┓┃┃┃┏┫┃╋┃┃");
      puts("\t\t\t\t┃┗━━┫┃╋┃┃┃┃┃┃┃╋┃┃┗┛┛┃┃╋┃┃");
      puts("\t\t\t\t┗━━┓┃┃╋┃┃┃┃┃┃┃╋┃┃┏┓┃┃┃╋┃┃");
      puts("\t\t\t\t┃┗━┛┃┗━┛┣┛┗┛┃┗━┛┃┃┃┗┫┗━┛┃");
      puts("\t\t\t\t┗━━━┻━━━┻━━━┻━━━┻┛┗━┻━━━┛");
      printf("\n");
      puts("\t\t\t  ╭━━╮╭━━━┳━╮╭━╮╱╭╮╱╱╭┳━━┳━╮╱╭┳━━━┳━━━╮");
      puts("\t\t\t  ┃╭╮┃┃╭━━┫┃╰╯┃┃╱┃╰╮╭╯┣┫┣┫┃╰╮┃┣╮╭╮┃╭━╮┃");
      puts("\t\t\t  ┃╰╯╰┫╰━━┫╭╮╭╮┃╱╰╮┃┃╭╯┃┃┃╭╮╰╯┃┃┃┃┃┃╱┃┃");
      puts("\t\t\t  ┃╭━╮┃╭━━┫┃┃┃┃┣━━┫╰╯┃╱┃┃┃┃╰╮┃┃┃┃┃┃┃╱┃┃");
      puts("\t\t\t  ┃╰━╯┃╰━━┫┃┃┃┃┣━━┻╮╭╯╭┫┣┫┃╱┃┃┣╯╰╯┃╰━╯┃");
      puts("\t\t\t  ╰━━━┻━━━┻╯╰╯╰╯╱╱╱╰╯╱╰━━┻╯╱╰━┻━━━┻━━━╯");
      puts("\t\t\t\t  【M】【E】【N】【U】");
      puts("");
      puts("\t\t\t\t    1 -【Fácil】");
      puts("\t\t\t\t    2 -【Médio】");
      puts("\t\t\t\t    3 -【Dificil】");
      puts("\t\t\t\t    4 -【Extras】");
      puts("\t\t\t\t    5 -【Sair】");
      scanf("%d", &num);
      switch (num)
      {
        case 1:
              geraMatriz(1);
              modofacil = TRUE;
              break;
        case 2:
              geraMatriz(2);
              modofacil = FALSE;
              break;
        case 3:
              geraMatriz(3);
              modofacil = FALSE;
              break;
        case 4:
              rankMelhores();
              break;
        case 5:
              system("clear");
              exit(1);
              break;
        default:
              menu();
      }
}

void rankMelhores()
{
  FILE *fp;
  int i, n = 0;//, vetor[6];
  char nome[50];
  int tempo, horas, horas_seg, minutos, segundos;

  fp = fopen("top5.txt","rt");
  if(fp == NULL)
  {
    fp = fopen("top5.txt","w");
    return;
  }
  else
  {
    int vetor[6] = {0,0,0,0,0,0};
    i = 0;
    while (fscanf(fp, "%s %d\n", nome, &vetor[i]) != EOF)
    {
      //printf("%s - %d\n", nome, vetor[i]);
      horas_seg = 3600;//horas em segundos
      horas = (vetor[i]/horas_seg); //resultado da hora
      minutos = (vetor[i] -(horas_seg*horas))/60;
      vetor[i] = (vetor[i] -(horas_seg*horas)-(minutos*60));

      printf("%s - %dh : %dm : %ds \n", nome, horas, minutos, vetor[i]);
    }
    system("read b");
    menu();
  }
}

// função para o ranking do sudoku
void top5(char *nomev,int s)
{
  Rank r[6];
  r[0].segundos = 0;
  r[1].segundos = 0;
  r[2].segundos = 0;
  r[3].segundos = 0;
  r[4].segundos = 0;
  r[5].segundos = 0;
  FILE *fp;
  int i, j, aux = 0, n=0;
  char auxnome[50];
  // abrir arquivo
  fp = fopen("top5.txt","rt");
  if(fp == NULL)
  {
    fp = fopen("top5.txt","w");
    fprintf(fp, "%s %d\n", nomev, s);
    return;
  }
  else
  {
    i = 0;
    while (fscanf(fp, "%s %d\n", r[i].nome, &r[i].segundos) != EOF)
    {
      i++;
    }
  }
    strcpy(r[i].nome , nomev);
    r[i].segundos = s;
    n = i + 1;

    // ordenar o TOP5
    for (i = 0; i < n; i++)
    {
      for (j = i + 1; j < n; j++)
      {
        if (r[i].segundos > r[j].segundos)
        {
            aux = r[j].segundos;
            strcpy(auxnome, r[j].nome);

            r[j].segundos = r[i].segundos;
            strcpy(r[j].nome, r[i].nome);

            r[i].segundos = aux;
            strcpy(r[i].nome, auxnome);
        }
      }
    }
    // modo escrita
    fp = fopen("top5.txt","w");
    //printf("n = %d",n);
    for (i = 0; i < 5; i++)
    {
        if (r[i].segundos != 0)
            fprintf(fp, "%s %d\n", r[i].nome, r[i].segundos);
    }
  fclose(fp);
}
// funcao para iniciar o jogo
void jogarSudoku()
{
  int n = 0, n2 = 0, num = 1, i, j, cont = 0, k = 0, op;
  char nome[20];
  int tempo, horas, horas_seg, minutos, segundos;
  int p1[81], p2[81];
  int total = 0;
  time_t tinicio, tfim;
  // célula do sudoku
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
  puts("Informe seu nome");
  scanf("%s", nome);

  printSudoku2();
  tinicio = time(NULL);

  // loop para receber as coordenadas
  while (TRUE)
  {
    puts("");
    puts("【M】【E】【N】【U】");
    puts("");
    puts(" 1 -【Fazer uma jogada】");
    puts(" 2 -【Apagar uma jogada】");
    puts(" 3 -【Verificar resposta】");
    puts(" 4 -【Desistir】");
    scanf("%d", &op);
    switch (op)
    {
      case 1:
          printf("Informe as coordenadas\n");
          scanf("%d", &n);
          scanf("%d", &n2);
          // saber se ja existe na posição incial
          if (n >= 1  && n <= 9 && n2 >= 1 && n2 <= 9)
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
              system("read b");
            }

          }
          else
          {
            printf("Coordenada inválida\n");
          }
          printSudoku2();
          //system("read b");
          break;

      case 2:
          printf("Informe as coordenadas\n");
          scanf("%d", &n);
          scanf("%d", &n2);
          // saber se ja existe na posição incial
          if (n >= 1  && n <= 9 && n2 >= 1 && n2 <= 9)
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
                sudoku2[n-1][n2-1] = 0;
            }
            else
            {
              printf("Célula do Sudoku\n");
              system("read b");
            }

          }
          else
          {
            printf("Coordenada inválida\n");
          }
          printSudoku2();
          //system("read b");
          break;
      case 3:
          tfim = time(NULL);
          if (verificaSudoku())
          {
              printf("Acertou Miserave\n");
              tempo = difftime(tfim, tinicio);

              top5(nome, tempo);

              horas_seg = 3600;//horas em segundos
              horas = (tempo/horas_seg); //resultado da hora
              minutos = (tempo -(horas_seg*horas))/60;
              segundos = (tempo -(horas_seg*horas)-(minutos*60));

              printf("Seu tempo de solução %dh : %dm :%ds \n",horas,minutos,segundos);
              system("read b");
          }
          else
          {
              printf("Errou Miserave\n");
              printf("Digite enter para continuar\n");
              system("read b");
          }
          break;
      case 4:
          break;
      default:
          printf("número inválido\n");
          break;
    }
    if (op == 4 || op == 3)
        break;
  }
}
// preenche o sudoku do arquivo sudoku.txt
void geraMatriz(int n)
{

  int c1, x, k = 0, i, j;
  char c;
  int vetor[81];
  FILE *fp;
  switch (n)
  {
    case 1:
          fp = fopen("facil.txt","r");
          if(fp == NULL)
          {
            printf("Não foi possivel abrir arquivo\n");
            return;
          }
          break;
    case 2:
          fp = fopen("medio.txt","r");
          if(fp == NULL)
          {
            printf("Não foi possivel abrir arquivo\n");
            return;
          }
          break;
    case 3:
          fp = fopen("dificil.txt","r");
          if(fp == NULL)
          {
            printf("Não foi possivel abrir arquivo\n");
            return;
          }
          break;
  }

  //srand( (unsigned)time(NULL) );
  x = 0;//(rand()%50);
  //printf("%d\n", x);
  i = 0;
  c1 = 0;
  while ((c = fgetc(fp)) != EOF)
  {
    if (c1 == x)
    {
      do
      {
        vetor[i] = c - '0';
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
  // passa os valores do arquivo para a matriz
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
// imprime sudoku do usuário
void printSudoku2()
{
  int i, j;
  printf("\033[39m");
  system("clear");

	for (i = 0; i< 9; i++)
  {
		//printf("\n");
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
			if (sudoku2[i][j] == 0)
				printf("|     |");
			else if (modofacil && sudoku[i][j] == sudoku2[i][j])
				printf("|  \033[32m%i\033[0m  |",sudoku2[i][j]);
      else if (modofacil)
        printf("|  \033[31m%i\033[0m  |", sudoku2[i][j]);
      else
        printf("|  %i  |", sudoku2[i][j]);
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

int verificaSudoku()
{
  int acertouMiserave = TRUE;
  int i, j;

  for (i = 0; i < 9; i++)
    for (j = 0; j < 9; j++)
      if(sudoku[i][j] != sudoku2[i][j])
        acertouMiserave = FALSE;

  if (acertouMiserave)
    return TRUE;
  else
    return FALSE;
  //system("read b");
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
