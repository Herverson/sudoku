#include "sudoku.h"

int main()
{

  int x = 0, y = 0;
  while (TRUE)
  {
    menu();
    geraMatrizUsuario();
    soluSudoku(x, y);
    jogarSudoku();
  }

  return 0;

}
