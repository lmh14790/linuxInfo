#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
extern int errno;
int main(){
	int res = mkfifo("my_fifo",0777);
	if(res == 0){ printf("FIFO created\n");}else{
	char *mesg = (char *)strerror(errno);
   printf("Mesg:%s\n",mesg); 
	}
	exit(EXIT_SUCCESS);
}
