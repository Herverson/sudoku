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
void geraMatriz(int);
void printSudoku2();
void jogarSudoku();
void geraMatrizUsuario();
void rankMelhores();
void top5(char *, int);
int verificaSudoku();
int mesmaColuna(int, int, int);
int mesmaLinha(int, int, int);
int mesmoQuadrado(int, int, int);
