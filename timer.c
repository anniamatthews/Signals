#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int x = 0; 
int count = 0; 
int tot_time = 0;
clock_t clock(void);
clock_t start_t, end_t;

void time(int signum){
  end_t = clock();
  tot_time = (end_t - start_t)/1000000;
  printf("The program has %d alarms and ran for %d seconds\n", count, tot_time);
  exit(1);
}

void handler(int signum){
  printf("Hello World!\n");
  x+=1;
  count+=1;
}

int main(int argc, char *argv[]){
  start_t = clock();
  while(1){
    signal(SIGINT, time);
    signal(SIGALRM,handler);
    alarm(1);
    while(x==0);
    printf("Turing was right!\n");
    x=0;
  }
  return 0; 
}