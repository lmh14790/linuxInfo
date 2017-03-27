#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(){
	FILE *readdir;
	char buffer[BUFSIZ+1];
	int chars_read;
   memset(buffer,'\0',sizeof(buffer));
   readdir = popen("ps ax","r");
   if(readdir != NULL ){
	   chars_read = fread(buffer,sizeof(char),BUFSIZ,readdir);
	   while(chars_read > 0){
		   buffer[chars_read-1]='\0';
		   printf("Reading %d:-\n %s\n",BUFSIZ,buffer);
		   chars_read = fread(buffer,sizeof(char),BUFSIZ,readdir);
	   }
	   pclose(readdir);
	   exit(EXIT_SUCCESS);
   }
	exit(EXIT_FAILURE);
	
	
}