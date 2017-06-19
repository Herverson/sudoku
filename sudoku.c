#include "sudoku.h"

int main()
{

  int x = 0, y = 0;
  geraMatriz();		
  printSudoku();
  soluSudoku(x, y);
  printSudoku();

  return 0;

}
