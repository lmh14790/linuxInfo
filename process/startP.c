#include <stdlib.h>
#include <stdio.h>
int main(){
	printf("running ps with system function\n");
	system("ps ax &");
	printf("running done.\n");
	exit(0);
    
}