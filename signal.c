/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");

  int x = 0;
  x+=1; 
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{

  while(1){
    signal(SIGALRM, handler); // 
    alarm(3); 
    int x = 0; 
    while(x==0);
    pritnf("Turing was right!\n");
    x=0;
  }
  
  return 0; //never reached
}