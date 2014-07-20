#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_INTR 4

int global_counter = 0;
int counter[NSIG]={0};

void handler(int sig) {
  global_counter++;
  counter[sig]++;
}

void print_stat(){
  int i;
  printf("\nCompteur global : %d \n", global_counter);
  for(i=0;i<=NSIG;i++){
    printf("\nCompteur pour le signal %d : %d \n",i,counter[i]);
  }
}

int main() {
  int i;
  for(i=0;i<=NSIG;i++){
    signal(i,handler);
  }
  
  while (1) {
    if(counter[SIGINT]>=MAX_INTR){
      print_stat();
      exit(EXIT_SUCCESS);
    }
  }


  return EXIT_SUCCESS;
}

