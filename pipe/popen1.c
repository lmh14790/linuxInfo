#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(){
	FILE *readdir;
	char buffer[1024];
	int chars_read;
   memset(buffer,'\0',sizeof(buffer));
   readdir = popen("uname -a","r");
   if(readdir != NULL ){
	   chars_read = fread(buffer,sizeof(char),1024,readdir);
	   if(chars_read > 0){
		   printf("output was :-\n%s\n",buffer);
	   }
	   pclose(readdir);
	   exit(EXIT_SUCCESS);
   }
	exit(EXIT_FAILURE);
	
	
}