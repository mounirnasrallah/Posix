#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int counter=0;

void incr_counter(int sig){
  counter++;
  printf("%d \n",counter);
}

int main (int argc, char* argv []) {

  int i;
  sigset_t sig_set;
  struct sigaction action;

  sigemptyset(&sig_set);
  //  sigaddset(&sig_set,SIGINT);
  sigaddset(&sig_set,SIGQUIT);
  sigprocmask(SIG_SETMASK, &sig_set, NULL);

  action.sa_handler = incr_counter;

  sigaction(SIGINT, &action,NULL);
  
  sleep(3);
  
  sigpending(&sig_set);

  for (i=1;i<NSIG;i++)
    if (sigismember(&sig_set,i))
      printf("\n Signal %d pendant \n",i);

  return EXIT_SUCCESS;
}
