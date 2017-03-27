#include "client.h"
#include <ctype.h>
//¿Í»§¶Ë
extern int errno;
int main()
{
	int ser_fifo_fd,client_fifo_fd;
	struct data_to_pass_st my_data;
	int times_to_send;
	char client_fifo[256];
	printf("process%d do open \n",getpid());
	ser_fifo_fd = open(SERVER_FIFO_NAME,O_WRONLY);
	printf("process%d do openfinish \n",getpid());
	if(ser_fifo_fd != 0){
		char *mesg = (char *)strerror(errno);
			fprintf(stderr,"Mesg:%s\n",mesg);
			
	}
	if(ser_fifo_fd == -1){
		fprintf(stderr,"sorry ,no server\n");
		exit(EXIT_FAILURE);
	}
	my_data.client_pid = getpid();
	sprintf(client_fifo,CLIENT_FIFO_NAME,my_data.client_pid);
	if(mkfifo(client_fifo,0777) == -1){
		fprintf(stderr,"sorry,can't make%s\n",client_fifo);
	    exit(EXIT_FAILURE);
	}printf("process%d do loop \n",getpid());
	for(times_to_send = 0;times_to_send < 5;times_to_send++){
		sprintf(my_data.some_data,"hellofrom %d\t",my_data.client_pid);
		printf("%d sent %s",my_data.client_pid,my_data.some_data);
		write(ser_fifo_fd,&my_data,sizeof(my_data));
		sleep(5);
		client_fifo_fd = open(client_fifo,O_RDONLY);
		if(client_fifo_fd != -1){
			if(read(client_fifo_fd,&my_data,sizeof(my_data))>0){
				printf("received:%s\n",my_data.some_data);
			}
			close(client_fifo_fd);
		}
	}
	close(ser_fifo_fd);
	unlink(client_fifo);
	exit(EXIT_SUCCESS);
	
	
}