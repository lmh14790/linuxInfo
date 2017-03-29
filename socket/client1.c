#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/un.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
extern int errno;
int main(){
	int sockfd;
	int len;
	struct sockaddr_un address;
	int result;
	char ch='A';
	sockfd = socket(AF_UNIX,SOCK_STREAM,0);
	address.sun_family = AF_UNIX;
	stpcpy(address.sun_path,"server_socket");
	len = sizeof(address);
	result = connect(sockfd,(struct sockaddr *)&address,len);
	if(result == -1){
		char *mesg = (char *)strerror(errno);
		fprintf(stderr,"Mesg:%s-----%s\n",mesg,"connect");
		exit(EXIT_FAILURE);	
	}
	write(sockfd,&ch,1);
	read(sockfd,&ch,1);
	printf("char from server = %c\n",ch);
	close(sockfd);
	exit(0);
}