#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/stat.h>

int check(char* path){

  struct stat stat_info;
  
  if (stat(path, &stat_info) == -1){
    fprintf(stderr,"Error file not exist");
    exit(EXIT_FAILURE);
  }

  if(S_ISDIR(stat_info.st_mode)){
    return 0;
  }
  else{
    return 1;
  }
}

int main(int argc, char* argv[]){

  int i;

  char option;
  char option_priv;

  if(argc>2){

    option = argv[1][0];

    if(check(argv[2])==1){
      switch(option){
      case 'e':
	if(unlink(argv[2]) == 0) {
	  printf("File deleted");
	}
	  else{
	    fprintf(stderr,"Error delete file");
	    exit(EXIT_FAILURE); 
	  }
	break;
      case 'c':

	if(argc>3){
	  option_priv = argv[3][0];
	}
	else{
	  fprintf(stderr, "Error number of arguments\n");
	  exit(EXIT_FAILURE);
	}
	
	if(( option_priv == 'R') | (option_priv == 'r')){
	  if(chmod(argv[2], S_IRGRP) == 0){
	    printf ("Access file modified \n ");
	  }
	  else{
	    fprintf(stderr,"Error chmod");
	    exit(EXIT_FAILURE);
	  }
	}
	else if((option_priv == 'W') || (option_priv == 'w')){
	  if(chmod(argv[2],S_IRGRP | S_IWGRP) == 0){
	    printf ("Access file modified \n ");
	  }
	  else {                                                            
	    fprintf(stderr,"chmod");                                        
	    exit(EXIT_FAILURE);
	  } 
	}
	break;
      case 'r':
	if(rename(argv[2],argv[3])==0){
	  printf("The file is renamed");
	}
	else{
	  printf("Error rename file");
	}
	break;
      default:
	fprintf(stderr,"Error options");
      }
    }
    else{
      fprintf(stderr,"No path directory please");
    }
  }
  
  else{
    fprintf(stderr,"Error number of arguments");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
