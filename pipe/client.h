#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<limits.h>
#define SERVER_FIFO_NAME "serv_fifo"
#define CLIENT_FIFO_NAME "cli_%d_fifo"
#define BUFFER_SIZE 20
//客户端服务器头文件
struct data_to_pass_st {
	pid_t client_pid;
	char some_data[BUFFER_SIZE -1];
	
};
