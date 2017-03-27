#include<unistd.h>
#include <stdio.h>
int main(){
char *const ps_argv[] = {"ps","ax","&",0};
char *const ps_envp[] = {"PATH=/bin:/usr/bin","TERM=console",0};
printf("starting running \n");
//execl("/bin/ps","ps","ax",0);
//execlp("ps","ps","ax",0);
//execle("/bin/ps","ps","ax",0,ps_envp);
//execv("/bin/ps",ps_argv);
//execvp("ps",ps_argv);
execve("/bin/ps",ps_argv,ps_envp);
printf("done \n");
}