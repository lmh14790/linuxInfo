#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<limits.h>
#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE PIPE_BUF
//消费者程序消费fifo里面的数据
extern int errno;
int main(int argc,char *argv[]){
	int pipe_fd ;
	int res;
	int open_mode = O_RDONLY;
	int bytes_sent = 0;
	char buffer[BUFFER_SIZE + 1];
	memset(buffer,'\0',sizeof(buffer));
	printf("process :%d opening FIFO\n",getpid());
	pipe_fd = open(FIFO_NAME,open_mode);
	printf("process :%d result :%d\n",getpid(),res);
if(pipe_fd != -1){
	do{
		res = read(pipe_fd,buffer,BUFFER_SIZE);
		bytes_sent += res;
	}while(res > 0);
(void)close(res);
}else{
			char *mesg = (char *)strerror(errno);
			fprintf(stderr,"Mesg:%s\n",mesg);
				exit(EXIT_FAILURE);
}
	printf("process :%d finished,result:%d\n",getpid(),bytes_sent);
	exit(EXIT_SUCCESS);
}
