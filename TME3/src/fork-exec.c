#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>


int main(int argc, char **argv) {
  
  struct timeval tv;
  
  printf("Resultat de la commande 'date'\n");
  
  switch(fork()){
  case -1: perror("Error fork()");
  case 0: 
    execlp("date", "date", "+%s", NULL);
  default:
    wait(NULL);
    gettimeofday(&tv, NULL);
    printf("%d\n", (int)tv.tv_sec);
    return 0;
  }
  
}



/*
  
  1) l'affichage qui résulte de l'exécution de ce programme est : 
  
  Resultat de la commande 'date'
  1362233376

  Tout simplement car la fonction execlp écrase le code suivant en cas de succès, donc en cas de succès de la ligne execlp("date", "date", "+%s", NULL),
  toutes les lignes suivantes ne sont pas exécutés.
  
  
 */
