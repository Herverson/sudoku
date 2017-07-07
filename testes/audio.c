#include<stdio.h>
#include<stdlib.h>
int main (){

  system("mpg123 Crawling.mp3 &");
  printf("teste\n");
  system("read b");
  system("clear");
  system("read b");
  system("killall mpg123");
  //system("start
  return 0;
}
