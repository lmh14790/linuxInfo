#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
pthread_mutex_t pthread_mutex;
void* thread_function(void* arg);
#define NUM_THREAD 6
int main(){
int res;
int i;
pthread_t a_thread[NUM_THREAD];
void* thread_result;
res = pthread_mutex_init(&pthread_mutex,NULL);
if(res != 0){
perror("mutex initialization failed");
exit(EXIT_FAILURE);
}
pthread_mutex_lock(&pthread_mutex);
for(i = 0;i< NUM_THREAD;i++ ){
res = pthread_create(&(a_thread[i]),NULL,thread_function,(void*)i);
pthread_mutex_unlock(&pthread_mutex);
if(res != 0){
perror("Thread create failed");
exit(EXIT_FAILURE);
//sleep(1);
}
	
}

printf("Waiting for thread to finish...\n");
for(i = NUM_THREAD-1;i>=0;i--){
res = pthread_join(a_thread[i],&thread_result);
if(res != 0){
perror("Thread join failed");
}else{
	printf("picked up a thread %d\n",i);
}
}
printf("all thread has stop\n");
exit(EXIT_SUCCESS);

}
//返回值为void*的函数
void* thread_function(void* arg){
	pthread_mutex_lock(&pthread_mutex);
	int rand_num,argv;
	argv = (int)arg;
	pthread_mutex_unlock(&pthread_mutex);
	printf("thread_function is runing,arg is %d\n",argv);
    rand_num = 1+(9*rand()/(RAND_MAX+1.0));
	sleep(rand_num);
	printf("bye from %d\n",argv);
pthread_exit(NULL);

}
