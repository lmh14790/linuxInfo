#include<sys/types.h>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

static int alarm_fired = 0;

void ding(int sig){

  alarm_fired = 1;

}

int main(){
 pid_t pid;

 printf("alram application starting \n");

 pid = fork();

 switch(pid) {
 
	 case -1:
		 perror("fork failed");
		 exit(1);
         case 0:
		 sleep(5);
                 kill(getppid(),SIGALRM);
                 exit(0);
         default:
                 printf("waiting for alarm to go off\n");
				 signal(SIGALRM,ding);
                 pause();
                 if(alarm_fired)
	         printf("ding-------------------------------\n");
                 printf("完成任务");
		exit(0); 
 
 
 
 
 }






}
