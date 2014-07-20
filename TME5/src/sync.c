#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void calcul_1 ( ) {
  int i;
  for (i = 0; i < 1E8; i++);
  kill(getppid(),SIGUSR1);
}

void calcul_2 () {
  int i;
  for (i = 0; i < 1E8; i++);
  kill(getppid(),SIGUSR1);
}

int main (int argc, char * argv[]) {
  int i=0;
  pid_t pid_fils[2];
  
  while ((i<2) && ((pid_fils[i] = fork())!=0))
    i++;
  /*
  calcul_1 ();
  
  waitpid();
  calcul_2 ();
  printf ("fin processus %d \n",i);             
  */
  return EXIT_SUCCESS;   
}
