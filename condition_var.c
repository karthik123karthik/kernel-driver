// condition variables are used to send signals between the threads about changes in the state of shared variable
// it also helps to define the sequence of thread execution

#include<stdio.h>
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

pthread_mutex_t mtx;
pthread_cond_t cond;
int shared_var = 0;
char buff[20];

void* thread1(void* arg){
    sleep(2);
    printf("THREAD 1 is called first\n");
    pthread_mutex_lock(&mtx);
    strcpy(buff, "Hello, World!");
    shared_var = 1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mtx);
}

void* thread2(void* arg){
    printf("THREAD2 is called first\n");
    pthread_mutex_lock(&mtx);
    if(shared_var == 0)pthread_cond_wait(&cond, &mtx);
    printf("the buffer value is %s\n", buff);
    pthread_mutex_unlock(&mtx);
}

int main(){
    pthread_t t1;
    pthread_t t2;

    if(pthread_create(&t1, NULL, thread1, NULL) == -1){
        perror("THREAD FAILED");
        return 0;
    }

    if(pthread_create(&t2, NULL, thread2, NULL) == -1){
        perror("THREAD FAILED");
        return 0;
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);


    return 0;
}
