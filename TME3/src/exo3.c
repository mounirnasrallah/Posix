#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc,char* argv[]){
  int i;
  int status;
  pid_t pid;
  int result=EXIT_SUCCESS;

  if(argc>2){
    
    for(i=2;i<argc;i++){  
      switch(pid=fork()){
      case -1: 
	perror("Error");
      case 0:
	printf("________ COMPILATION _________ \n");
	execl("/usr/bin/gcc","-c -Wall","-I",argv[1],argv[i],NULL);
      default:
	waitpid(pid,&status,0);
	if(status!=EXIT_SUCCESS){
	  result = EXIT_FAILURE;
	}
      }
    }
    
    if(result==EXIT_SUCCESS){
      printf("________ COMPILATION FINALE  _________ \n");
      execl("/usr/bin/gcc","-o","affiche","*.o",NULL);
    }
  }

  else{
    printf("exo3 [include_path] <files.c>");
  }
  return EXIT_FAILURE;
}
