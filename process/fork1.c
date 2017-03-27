#include <unistd.h>  
#include <stdio.h>
#include <malloc.h>
#include<string.h>
int main(void)  
{  
   char temp[BUFSIZ + 1];
	memset(temp,'\0',sizeof(temp));
   int i=0;  
   for(i=0;i<3;i++){
      temp[i] = '	';
       pid_t fpid=fork();   
       if(fpid==0)  
           printf("%sthis is sonprocess father:%d---self:%d---\n",temp,getppid(),getpid());  
       else  
           printf("%sthis is fatherprocess father:%d----self:%d---\n",temp,getppid(),getpid());  
   }  
 
   return 0;  
  
}
