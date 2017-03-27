#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(){
	int data_processed;
	int file_pipes[2];
	const char some_data[] = "123";
	char buffer[BUFSIZ + 1];
	pid_t forkResult;
	int stat;
	memset(buffer,'\0',sizeof(buffer));
	if(pipe(file_pipes) == 0){
		forkResult = fork();
		if(forkResult == -1){
			fprintf(stderr,"fork failure");
			exit(EXIT_FAILURE);
		}
		if(forkResult == 0){
		data_processed = read(file_pipes[0],buffer,BUFSIZ);
		printf("read %d bytes:%s\n",data_processed,buffer);
		exit(EXIT_SUCCESS);
		}else {
			data_processed = write(file_pipes[1],some_data,strlen(some_data));
		    printf("wrote %d bytes\n",data_processed);
		}
	 
	}
 int stat_val;
 pid_t child_pid;

 child_pid = wait(&stat_val);
 printf("Child has finished: PID = %d\n",child_pid);
 if(WIFEXITED(stat_val) != 0)
	 printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
 else
	 printf("Child terminated abnormally\n");



	exit(EXIT_SUCCESS);
}
