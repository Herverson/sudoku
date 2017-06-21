#include "sudoku.h"

int main()
{

  int x = 0, y = 0;
  geraMatriz();
  geraMatrizUsuario();
  printSudoku();
  soluSudoku(x, y);
  jogarSudoku();
  //printSudoku();

  return 0;

}
