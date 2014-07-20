#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N_FILS 5




int main(int argc, char* argv[]){

  int* array_pid = calloc(N_FILS,sizeof(int));
  int i,j;
  pid_t pid;
  
 etiquette:

  switch(pid=fork()){
  case -1:
    perror("Error");
  case 0:
    array_pid[i]=getpid();
    i++;
    if(i<N_FILS){
      goto etiquette;
    }
    if(i==N_FILS){
      for(j=0;j<N_FILS;j++){
	printf("[ %d ] --> %d \n",j,array_pid[j]);
      }
    }
  default:
    wait(NULL);
  }
  
  return EXIT_SUCCESS;
}


/*

1 ) Il serait impossible de réaliser cet affichage par le programme principal, car le tableau array_pid du programme principal ne contient pas les entrés de ses processus fils.

2 ) Non plus pour les même raisons.

 */


