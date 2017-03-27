#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>

void* thread_function(void* arg);
pthread_mutex_t work_mutex;

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;

int main(){
int res;
pthread_t a_thread;
void* thread_result;

res = pthread_mutex_init(&work_mutex,NULL);
if(res != 0){
perror("mutex initialization failed");
exit(EXIT_FAILURE);
}
res = pthread_create(&a_thread,NULL,thread_function,NULL);
if(res != 0){
perror("Thread create failed");
exit(EXIT_FAILURE);
}
//锁和解锁之间的代码是同步代码
pthread_mutex_lock(&work_mutex);
printf("Input some text . Enter 'end' to finish\n");
while(!time_to_exit){
	fgets(work_area,WORK_SIZE,stdin);
	pthread_mutex_unlock(&work_mutex);
	
	while(1){
		//判断数组中是否有值如果有值则sleep 1秒等待子线程处理
	    pthread_mutex_lock(&work_mutex);
		if(work_area[0] != '\0'){
			pthread_mutex_unlock(&work_mutex);
			sleep(1);
		}else{
			break;
		}
		
	}
}
pthread_mutex_unlock(&work_mutex);
printf("\nWaiting for thread to finish ...\n");
res = pthread_join(a_thread,&thread_result);
if(res != 0){
perror("Thread join failed");
exit(EXIT_FAILURE);
}
printf("Thread joined,it turend  %s\n",(char*)thread_result);
pthread_mutex_destroy(&work_mutex);
exit(EXIT_SUCCESS);

}
//返回值为void*的函数
void* thread_function(void* arg){
sleep(1);
pthread_mutex_lock(&work_mutex);
while(strncmp("end",work_area,3) !=0 ){
	printf("You input %d characters\n",strlen(work_area)-1);
	work_area[0] = '\0';
	pthread_mutex_unlock(&work_mutex);
	sleep(1);
	//判断数组中是否有值如果没有值则sleep 1秒等待主线程往数组中增加值
	pthread_mutex_lock(&work_mutex);
	while(work_area[0] == '\0'){
		pthread_mutex_unlock(&work_mutex);
		sleep(1);
		pthread_mutex_lock(&work_mutex);
	}
}
time_to_exit = 1;
work_area[0] = '\0';
pthread_mutex_unlock(&work_mutex);
pthread_exit(NULL);

}
