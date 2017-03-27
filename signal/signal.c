#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void ouch(int sig){
printf("ouchc - i got a gignal %d \n",sig);
signal(SIGINT,SIG_DFL);
}

int main(){
	signal(SIGINT,&ouch);
while(1) {
printf("我正在执行\n");
sleep(1);

}

}
