#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
  int num;
  do
  {
      system("clear");
      printf("\033[34m");
      puts("\t\t\t  ╭━━╮╭━━━┳━╮╭━╮╱╭╮╱╱╭┳━━┳━╮╱╭┳━━━┳━━━╮");
      puts("\t\t\t  ┃╭╮┃┃╭━━┫┃╰╯┃┃╱┃╰╮╭╯┣┫┣┫┃╰╮┃┣╮╭╮┃╭━╮┃");
      puts("\t\t\t  ┃╰╯╰┫╰━━┫╭╮╭╮┃╱╰╮┃┃╭╯┃┃┃╭╮╰╯┃┃┃┃┃┃╱┃┃");
      puts("\t\t\t  ┃╭━╮┃╭━━┫┃┃┃┃┣━━┫╰╯┃╱┃┃┃┃╰╮┃┃┃┃┃┃┃╱┃┃");
      puts("\t\t\t  ┃╰━╯┃╰━━┫┃┃┃┃┣━━┻╮╭╯╭┫┣┫┃╱┃┃┣╯╰╯┃╰━╯┃");
      puts("\t\t\t  ╰━━━┻━━━┻╯╰╯╰╯╱╱╱╰╯╱╰━━┻╯╱╰━┻━━━┻━━━╯");
      printf("\n");
      printf("\n");
      //puts("🅜 🅔 🅝 🅤");
      //printf("\033[39m");
      puts("\t\t\t\t┏━━━┳┓╋┏┳━━━┳━━━┳┓┏━┳┓╋┏┓");
      puts("\t\t\t\t┃┏━┓┃┃╋┃┣┓┏┓┃┏━┓┃┃┃┏┫┃╋┃┃");
      puts("\t\t\t\t┃┗━━┫┃╋┃┃┃┃┃┃┃╋┃┃┗┛┛┃┃╋┃┃");
      puts("\t\t\t\t┗━━┓┃┃╋┃┃┃┃┃┃┃╋┃┃┏┓┃┃┃╋┃┃");
      puts("\t\t\t\t┃┗━┛┃┗━┛┣┛┗┛┃┗━┛┃┃┃┗┫┗━┛┃");
      puts("\t\t\t\t┗━━━┻━━━┻━━━┻━━━┻┛┗━┻━━━┛");
      //printf("\033[33m");
      puts("【M】【E】【N】【u】");
      puts("");
      puts("1 -【Fácil】");
      puts("2 -【Médio】");
      puts("3 -【Dificil】");
      puts("4 -【Extras】");
      puts("5 -【Sair】");
      scanf("%d", &num);
      switch (num)
      {
        case 1:
              //facil();
              break;
        case 2:
              //medio();
              break;
        case 3:
              //dificil();
              break;
        case 4:
              //extras();
              break;
      }
      
  } while(num != 5);
  return 0;
}
