#include <stdio.h>
#include <stdlib.h>
#include "converters.h"
#include <sys/unistd.h>
#include <string.h>


int main(int argc, char* argv[])
{
  int i;
  pid_t pid;

  char src_currency[4], target_currency[4];
  float amount;

  amount = atof(argv[2]);

  if(argc==3){
    
    printf("Conversion for : %s %.3f \n",argv[1],amount);         
    
    for(i=0;i<NB_CONVERTERS;i++){
            
      switch(fork()){
      case -1:
	fprintf(stderr,"Error fork() -- line : %s file : $d",__FILE__,__LINE__);
	exit(EXIT_FAILURE);
      case 0:
	strcpy(target_currency,determine_currency(i));
	strcpy(src_currency,argv[2]);
	printf("%s %.3f \n",target_currency,convert(argv[1],target_currency,amount));
	exit(EXIT_SUCCESS);
      default:
	wait(NULL);
      }
    }
  }
  
  else{
    fprintf(stderr,"No arguments");
  }

  printf("End of Conversion");

  return EXIT_SUCCESS;
}

