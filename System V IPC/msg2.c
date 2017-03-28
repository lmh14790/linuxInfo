#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/ipc.h>
#define MAX_TEXT 512
extern int errno;
struct my_msg_st {
	long int my_msg_type;
	char some_text[MAX_TEXT];
};
int main(){
	int running = 1;
	int  msgid;
	struct my_msg_st some_data;
	char buffer[BUFSIZ];
	msgid = msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid == -1){
		char *mesg = (char *)strerror(errno);
			fprintf(stderr,"Mesg:%s-----%s\n",mesg,"msgget");
		exit(EXIT_FAILURE);
	}
	while(running){
		printf("Enter some text");
		fgets(buffer,BUFSIZ,stdin);
		some_data.my_msg_type = 1;
		strncpy(some_data.some_text,buffer,MAX_TEXT);
		if(msgsnd(msgid,(void *)&some_data,MAX_TEXT,0) == -1)
		{
			char *mesg = (char *)strerror(errno);
			fprintf(stderr,"Mesg:%s\n",mesg);
		    exit(EXIT_FAILURE);
		}
		if(strncmp(some_data.some_text,"end",3) == 0){
			running = 0;
		}
		
	}
	exit(EXIT_SUCCESS);
}