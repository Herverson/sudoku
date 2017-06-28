#include "sudoku.h"

int main()
{

  int x = 0, y = 0;
  while (TRUE)
  {
    menu();
    geraMatrizUsuario();
    printSudoku2();
    soluSudoku(x, y);
    jogarSudoku();
  }

  return 0;

}
