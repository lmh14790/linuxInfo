#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void* thread_function(void* arg);

int main(){
int res;
pthread_t a_thread;
void* thread_result;

res = pthread_create(&a_thread,NULL,thread_function,NULL);
if(res != 0){
perror("Thread create failed");
exit(EXIT_FAILURE);
}
sleep(5);
printf("Canceling son thread ...\n");
	res = pthread_cancel(a_thread);
if(res != 0){
perror("Thread Canceling failed");
exit(EXIT_FAILURE);
}
printf("Waiting for son thread to finish...\n");
res = pthread_join(a_thread,&thread_result);
if(res != 0){
perror("Thread join failed");
exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);

}
//返回值为void*的函数
void* thread_function(void* arg){
	int i,res;
	res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
	if(res != 0){
		perror("Thread pthread_setcancelstate failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);
	//res = pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
	if(res != 0){
		perror("Thread pthread_setcanceltype failed");
		exit(EXIT_FAILURE);
	}
printf("son Thread_function is running\n");
while(1){
	printf("thread is still working\n");
	sleep(1);
}
printf("son thread ending...\n");
pthread_exit(NULL);
}
