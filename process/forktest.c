#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
pid_t pid;
char *message;
int n;
int exitCode;

printf("fork program starting ==================\n");

pid = fork();
switch(pid){
	case -1:
		perror("fork failed");
		exit(1);
	case 0:
	        message = "This is the child";
	        n = 5;
		exitCode = 37;
	        break;
	default:
	        message = "This is the parent";
	        n = 3;
		exitCode = 0;
	        break;	





}
   for (;n>0;n--){
   
   puts(message);
   sleep(1);
      
   }
  if(pid != 0){
 int stat_val;
 pid_t child_pid;
 child_pid = wait(&stat_val);
 printf("Child has finished: PID = %d\n",child_pid);
 if(WIFEXITED(stat_val) != 0)
	 printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
 else
	 printf("Child terminated abnormally\n");

}  

exit(exitCode);


}
