#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void* thread_func(void *str){
    printf("Thread function pid:%d\n", getpid());
    printf("Thread function %s\n", (char*)str);
    pthread_detach(pthread_self()); // detaching the thread
    sleep(20);
    printf("Thread function exited pid:%d\n", getpid());
    // exit(0);  this will terminate the process hence suggested to use
    pthread_exit(0);
}
 

int main(){
    pthread_t thread1;

    int ret = pthread_create(&thread1, NULL, thread_func, "Thread 1");
    if(ret!=0){
        printf("Thread creation failed\n");
        exit(1);
    }
    sleep(10);
    // pthread_join(thread1, NULL); // wait for thread1 to exit
    printf("main thread exited pid:%d \n", getpid());
    // exit(0) if I use this then main thread will exit and all other threads will also exit
    pthread_cancel(thread1); // this will cancel the thread1
    pthread_exit(0); //if I use this then main thread will exit and all other threads will continue to run
    // return 0;
}
