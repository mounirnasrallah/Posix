#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>


int rediriger_stdout(char *nom_fichier){ 
 
  int file = open(nom_fichier, O_RDWR| O_CREAT | O_SYNC,0600);
  if (file==-1) {
    fprintf(stderr,"Error");
    return EXIT_FAILURE;
  }
  else{
    dup2(file,STDOUT_FILENO);
    return EXIT_SUCCESS;
  }
}


void restaurer_stdout(){
  dup2(STDIN_FILENO,STDOUT_FILENO);
}

int main (int argc, char* argv []) {
  printf ("avant la redirection \n") ;
  rediriger_stdout ("fichier.out") ;
  printf ("après la redirection \n") ;
  restaurer_stdout();
  printf ("après avoir restauré stdout \n") ;
  return EXIT_SUCCESS;
}
