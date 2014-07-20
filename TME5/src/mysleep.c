#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 
#include <unistd.h> 
 

void handle_sigalrm(int sig) {
  if (sig != SIGALRM) {
    fprintf(stderr, "Wrong signal: %d\n", sig);
  }
  printf("End of sleep\n");
}

void mysleep(int sec){

  struct sigaction action;
  sigset_t mask;

  action.sa_handler = &handle_sigalrm;
  action.sa_flags = SA_RESETHAND;
  sigfillset(&action.sa_mask);
  sigaction(SIGALRM, &action, NULL);

  sigprocmask(0, NULL, &mask);
  sigdelset(&mask, SIGALRM);

  alarm(sec);
  sigsuspend(&mask);

  return;
}

 
int main(int argc,char* argv[]) {

  if(argc==2){

    int sec = atol(argv[1]);
    
    struct sigaction action;
    
    action.sa_handler = SIG_IGN;
    action.sa_flags = SA_RESTART;
    sigfillset(&action.sa_mask);
    
    sigaction(SIGHUP, &action, NULL); 
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGKILL, &action, NULL);
    sigaction(SIGINT, &action, NULL);
        
    mysleep(sec);
    
  }
  
  else{
    fprintf(stderr,"./mysleep seconds ");
  }

  return EXIT_SUCCESS;
}


 
