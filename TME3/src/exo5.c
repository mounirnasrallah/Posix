#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
  
  char c;
  char* value = getenv("COUNTER");

  if(value==NULL){
    setenv("COUNTER","0",1);
    c='0';
    value="0";
  }
  else{
    c = value[0];
  }
  
  
  if(c<'5'){
    c=c+1;
    setenv("COUNTER",&c,1);
    printf("Mon PID est : %d \n",getpid());
    execl("./exo5","",NULL);
  }
  else{
  }
  
  return EXIT_SUCCESS;
}
