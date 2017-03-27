#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void* thread_function(void* arg);
char message[] = "hello world";
int run_now = 0;
int count =0;
int main(){
int res;
pthread_t a_thread;
void* thread_result;
res = pthread_create(&a_thread,NULL,thread_function,NULL);

int print_count1 = 0;
run_now = 1;
while(print_count1++ <= 20){
	count++;
	printf("mian thread working -----------------------\n");
	sleep(5);
	if(run_now == 1){
		//count ++;
		run_now = 2;	
	}
}
if(res != 0){
perror("Thread create failed");
exit(EXIT_FAILURE);
}
printf("\nWaiting for thread to finish %d ...\n",count);
//res = pthread_join(a_thread,&thread_result);
/**if(res != 0){
perror("Thread join failed");
exit(EXIT_FAILURE);
}*/
exit(EXIT_SUCCESS);

}
//返回值为void*的函数
void* thread_function(void* arg){
int print_count1 = 0;
while(print_count1++ <= 20){
	count++;
	printf("child thread working -----------------------\n");
	if(run_now == 2){
		//count ++;
		printf("2");
		run_now = 1;
		
	}



}
pthread_exit("Thank you for CPU time");
}