#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(){
	FILE *writedir;
	char buffer[BUFSIZ+1];
	int chars_read;
  sprintf(buffer,"first time i got u...\n");
  writedir = popen("od -c","w");
   if(writedir != NULL ){
	   fwrite(buffer,sizeof(char),strlen(buffer), writedir);
	   pclose(writedir);
	   exit(EXIT_SUCCESS);
   }
	exit(EXIT_FAILURE);
	
	
}