#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FALSE 0
#define TRUE 1

int soluSudoku(int, int);
void menu();
void geraMatriz(int);
void printSudoku2();
void jogarSudoku();
void geraMatrizUsuario();
void verificaSudoku();
int mesmaColuna(int, int, int);
int mesmaLinha(int, int, int);
int mesmoQuadrado(int, int, int);
