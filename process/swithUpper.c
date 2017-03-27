#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
	char *fileName;
	if(argc != 2){
		fprintf(stderr,"usage: userupper file \n");
		exit(1);
	}
	fileName = argv[1];
	if(!freopen(fileName,"r",stdin)){
		fprintf(stderr,"cound not redirect sdtin from file %s\n",fileName);
		exit(2);
	}
	execl("./upper","upper",0);
	perror("counld not exec ./upper");
	exit(3);
}