
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

#define N_FILS 7





/* ----------------------
  Exercice 1
----------------------- */

void exo_I_a(){
  int i;
  pid_t pid;

  for(i=0;i<N_FILS;i++){

    pid=fork();

    switch(pid){
    case -1:
      fprintf(stderr,"Erreur lors de l'appel à fork");
      exit(EXIT_FAILURE);
    case 0:
      printf("Je suis un processus fils, mon pid est le %d, mon père est %d \n",getpid(),getppid());
      exit(0);
    default:;
    }
  }
  
  exit(EXIT_SUCCESS);
}




void exo_I_b(int* i){
  if(*i<N_FILS){
    pid_t pid;
    pid=fork();
    *i = *i + 1;    
    switch(pid){
    case -1: fprintf(stderr,"Erreur lors de la création du fils");
      exit(EXIT_FAILURE);
    case 0:
      printf("Je suis un processus fils, mon pid est le %d, mon père est %d \n",getpid(),getppid());
      exit(0);
    default:
      exo_I_b(i);
    }
  }
  exit(EXIT_SUCCESS);
}





/* -------------------
   Exercice 2
-----------------------*/

//  Attendre 1 fils quelconque

void exo_II_1(){
  int i;
  pid_t pid;

  for(i=0;i<N_FILS;i++){
    pid=fork();

    switch(pid){
    case -1:
      fprintf(stderr,"Erreur lors de l'appel à fork");
      exit(EXIT_FAILURE);
    case 0:
      printf("Je suis un processus fils, mon pid est le %d, mon père est %d \n",getpid(),getppid());
      exit(EXIT_SUCCESS);
    default:;}
  }
  
  wait(NULL);

  exit(EXIT_SUCCESS);
}




//  Attendre tous les fils, 
void exo_II_2(){
  int i;
  pid_t pid;

  for(i=0;i<N_FILS;i++){
    pid=fork();
    switch(pid){
    case -1:
      fprintf(stderr,"Erreur lors de l'appel à fork");
      exit(EXIT_FAILURE);
    case 0:
      printf("Je suis un processus fils, mon pid est le %d, mon père est %d \n",getpid(),getppid());
      exit(EXIT_SUCCESS);
    default:
      wait(NULL);
    }
  }
  exit(EXIT_SUCCESS);
}
  


// Attendre le dernier fils créé uniquement.
void exo_II_3(){
  int i,status;
  pid_t pid;

  for(i=0;i<N_FILS;i++){
    pid=fork();
    switch(pid){
    case -1:
      fprintf(stderr,"Erreur lors de l'appel à fork");
      exit(EXIT_FAILURE);
    case 0:
      printf("Je suis un processus fils, mon pid est le %d, mon père est %d \n",getpid(),getppid());
      exit(EXIT_SUCCESS);
    default:
      if(i==N_FILS-1){
       	waitpid(pid,&status,0);
      }
    }
  }
  exit(EXIT_SUCCESS);
}


/* ------------------------
   Exercice 3
   --------------------- */


// Réponse : 6 Processus créés
 

int exo_III_main (int arg, char* argv[]) {
  int i, j, p;
  int status;
  
  for (i=0; i<3 ; i++)
    if ((p=fork ()) == 0) {
      printf ("i=%d\n", i);
      j=0;
      while (j<i && ((p=fork()) == 0))	
	j++;
      if (p==0)
	printf("j=%d \n",j);
      else{
	wait(&status);}
      exit(j);
    } 
  else{
    wait(&status);
  }
  return (0);
}


/* --------------------
   Main
 -------------------- */

int main(){
  int i = 0;

  exo_II_1();

}
