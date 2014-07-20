#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>

#define NBSEC 2

sigjmp_buf env;


void action_child(int sig){
  printf("\n Fils mort %d \n",sig);  
}

int main(int argc, char* argv[]){

  sigset_t sig_set, old_sig_set;
  struct sigaction action;
  pid_t pid;

  sigemptyset(&sig_set);
  sigprocmask(SIG_SETMASK, &sig_set,NULL);
  sigaddset(&sig_set, SIGCHLD);
  sigprocmask(SIG_SETMASK, &sig_set,&old_sig_set);
  
  pid = fork();
  
  switch(pid){
  case -1: 
    fprintf(stderr,"Error");
    exit(EXIT_FAILURE);
  case 0:
    printf("\nFils ----- pid : %d ----- ppid : %d \n",getpid(),getppid());
    exit(0);
  default:  
    action.sa_flags = 0;
    action.sa_handler = action_child;
    sigaction(SIGCHLD, &action, NULL);
    sleep(NBSEC); 
    sigsuspend(&old_sig_set);
  } 

   return EXIT_SUCCESS;
}


