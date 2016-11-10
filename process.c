#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>

static void sighandler( int signo ){
  if(signo == SIGINT){
    printf("Signal Interrupted\n");
  }else if(signo == SIGUSR1){
    printf("Parent ID: %d\n", getppid());
  }
}


int main(){
  
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);

  printf("hello\n");
  while(1){
    printf("The PID is: %d\n",getpid());
    sleep(1);
  }

  return 0;
}
