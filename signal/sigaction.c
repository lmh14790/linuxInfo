#include<signal.h>
#include<stdio.h>
#include<unistd.h>
int i = 0;
void ouch(int sig){
printf("ouchc - i got a gignal %d \n",sig);
//signal(SIGINT,SIG_DFL);
i++;
if(i == 2){
kill(getpid(),SIGQUIT);
i = 0; 
}
 
}

int main(){
	struct sigaction act;
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT,&act,0);
while(1) {
printf("i am working \n");
sleep(1);
}

}