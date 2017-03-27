#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#define FIFO_NAME "my_fifo"
extern int errno;
int main(int argc,char *argv[]){
	int res ;
	int open_mode = 0;
	int i;
	if(argc < 2){
		fprintf(stderr,"usga: %s < some combination of\
		O_RDONLY O_WRONLY O_NONBLOCK>\n",*argv);
		exit(EXIT_FAILURE);
	}
	int j = 0;
    for(j = 1;j< argc;j++){
		if(strncmp(*++argv,"O_RDONLY",8) == 0)
			open_mode |= O_RDONLY;
		if(strncmp(*argv,"O_WRONLY",8) == 0)
			open_mode |= O_WRONLY;
		if(strncmp(*argv,"O_NONBLOCK",10) == 0)
			open_mode |= O_NONBLOCK;
	}
	if(access(FIFO_NAME,F_OK) == -1){
		res = mkfifo(FIFO_NAME,0777);
		if(res != 0){
				char *mesg = (char *)strerror(errno);
			fprintf(stderr,"Mesg:%s\n",mesg);
				exit(EXIT_FAILURE);
		}
	}
	printf("process :%d opening FIFO\n",getpid());
	res = open(FIFO_NAME,open_mode);
	printf("process :%d result :%d\n",getpid(),res);
	sleep(5);
	if(res != -1) (void)close(res);
	printf("process :%d finished\n",getpid());
	exit(EXIT_SUCCESS);
}
