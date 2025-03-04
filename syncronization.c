#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int global_val = 0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void *thread1(void *arg){
    int i;
    pthread_mutex_lock(&mtx);
    for(i=0; i<5; i++){
        global_val++;
        printf("Thread 1: %d\n", global_val);
    }
    pthread_mutex_unlock(&mtx);
    printf("THREAD 1 completed\n");
    return NULL;
}

void *thread2(void *arg){
    int i;
    pthread_mutex_lock(&mtx);
    for(i=0; i<5; i++){
        global_val++;
        printf("Thread 2: %d\n", global_val);
    }
    pthread_mutex_unlock(&mtx);
    printf("THREAD 2 completed\n");
    return NULL;
}

// In case of mutex please take care of deadlock scenarios by following some heirarchy

int main(){
    pthread_t t1, t2;

    int ret1 = pthread_create(&t1, NULL, thread1, NULL);
    if(ret1){
        printf("Error creating thread 1\n");
        exit(1);
    }

    int ret2 = pthread_create(&t2, NULL, thread2, NULL);
    if(ret2){
        printf("Error creating thread 2\n");
        exit(1);
    }

    // to compile pthread use -lpthread flag it is a library to use pthread functions
     ret1 = pthread_join(t1, NULL);
     if(ret1){
        printf("Error joining thread 1\n");
        exit(1);
     }
     ret2 =  pthread_join(t2, NULL);
     if(ret2){
        printf("Error joining thread 2\n");
        exit(1);
     }

     printf("global value : %d\n", global_val);
    return 0;
}
