#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int tempo, horas, horas_seg, minutos, segundos;

  time_t tinicio, tfim;
  tinicio = time(NULL);
  system("read b");
  tfim = time(NULL);
  tempo = difftime(tfim, tinicio);
  printf("%d\n", tempo);


  horas_seg = 3600;//horas em segundos
  horas = (tempo/horas_seg); //resultado da hora
  minutos = (tempo -(horas_seg*horas))/60;
  segundos = (tempo -(horas_seg*horas)-(minutos*60));
  printf("%dh : %dm :%ds \n",horas,minutos,segundos);

  return 0;
}
