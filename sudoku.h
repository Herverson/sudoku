#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FALSE 0
#define TRUE 1
struct rank
{
  char nome[50];
  int segundos;
};
typedef struct rank Rank;

int soluSudoku(int, int);
void menu();
void adicionaQuant(int);
void geraMatriz(int);
void printSudoku();
void jogarSudoku();
void geraMatrizUsuario();
void rankMelhores();
void imprimeRank(char *);
void top5(char *, int);
int verificaSudoku();
int mesmaColuna(int, int, int);
int mesmaLinha(int, int, int);
int mesmoQuadrado(int, int, int);
