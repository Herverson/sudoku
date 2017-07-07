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

void menu();
void ET();
void adicionaQuant(int);
void geraMatriz(int);
void printSudoku();
void printSudoku2();
void printSudoku3();
void jogarSudoku();
void rankMelhores();
void imprimeRank(char *);
void top5(char *, int);
int verificaSudoku();
