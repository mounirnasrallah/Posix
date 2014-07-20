/**** decoder.c ****/

#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "decoder.h"


#define _POSIX_SOURCE 1

int magicsq[3][3] = {{4, -1, 8}, {-1, -1, -1}, {2, -1, 6}};

int check() {
	int i, j, sums[8];
	for (i = 0; i < 8; i++) 
		sums[i] = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			sums[i] += magicsq[i][j];
			sums[i+3] += magicsq[j][i];
			if (i == j) sums[6] += magicsq[i][j];
			if ((i+j) == 2) sums[7] += magicsq[i][j];
		}
	}
	int result = 1;
	i = 1;
	while ((i < 8) && (result == 1)) {
		if (sums[0] != sums[i])
			result = 0;
		i++;
	}
	return result;
}


void display() {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("  %d", magicsq[i][j]);
		printf("\n");
	}
	printf("\n");
}


int solve(int x){

  int compute = 0;
  register int i,j;
  register int b,c,d,e;

  
  magicsq[0][1] = x;  
  
  for(b=0;b<10;b++){
    magicsq[1][0]=b;
    
    for(c=0;c<10;c++){
      magicsq[1][1]=c;
      
      for(d=0;d<10;d++){
	magicsq[1][2]=d;
	
	for(e=0;e<10;e++){
	  magicsq[2][1]=e;
	  
	  if(check()==1){
	    compute++;
	    display();
	  }
	}
      }
    }
  }
  return compute;
}


int main(int argc, char **argv)
{	
  /* LANCEMENT ET ATTENTE DES PROCESSUS FILS */
  int i,status;
  pid_t pid;
  int cmpt = 0;

  for(i=0;i<10;i++){
    pid=fork();
    switch(pid){
    case -1:
      fprintf(stderr,"Erreur lors de l'appel à fork() -- Fichier : %s Linge : %d \n",__FILE__,__LINE__);
      exit(EXIT_FAILURE);
    case 0:
      solve(i);
    default:
      wait(&status);
      }
    }
   
  return EXIT_SUCCESS;
}
