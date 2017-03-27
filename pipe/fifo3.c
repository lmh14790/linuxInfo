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
#define TEN_MEG (1024*1024*10)
//生产者程序添加数据到fifo文件
extern int errno;
int main(){
	int pipe_fd ;
	int res;
	int open_mode = O_WRONLY;
	int bytes_sent = 0;
	char buffer[BUFFER_SIZE + 1];
	if(access(FIFO_NAME,F_OK) == -1){
		res = mkfifo(FIFO_NAME,0777);
		if(res != 0){
				char *mesg = (char *)strerror(errno);
			fprintf(stderr,"Mesg:%s\n",mesg);
				exit(EXIT_FAILURE);
		}
	}
	printf("process :%d opening FIFO\n",getpid());
	pipe_fd = open(FIFO_NAME,open_mode);
	printf("process :%d result :%d\n",getpid(),res);
if(pipe_fd != -1){
while(bytes_sent < TEN_MEG){
	res = write(pipe_fd,buffer,BUFFER_SIZE);
	if(res == -1){
		fprintf(stderr,"Write error on pipe \n");
		exit(EXIT_FAILURE);
	}
	bytes_sent +=res;
}	
(void)close(res);
}else{
			char *mesg = (char *)strerror(errno);
			fprintf(stderr,"Mesg:%s\n",mesg);
				exit(EXIT_FAILURE);
}
	printf("process :%d finished result:%d\n",getpid(),bytes_sent);
	exit(EXIT_SUCCESS);
}
