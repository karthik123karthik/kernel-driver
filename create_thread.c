// Threads - A thread is a lightweight process. It is a basic unit of CPU utilization that comprises a thread ID, a program counter, a register set, and a stack. Threads share with other threads belonging to the same process their code section, data section, and other operating system resources, such as open files and signals.
// Each thread maintains its own stack, registers, and signal mask. Threads are sometimes called lightweight


#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* thread_func(void* arg){
    int num = atoi((char*)arg);
    sleep(num);
    printf("Exiting thread\n");
    pthread_exit(0);
}

int main(){
    pthread_t t;
    if (pthread_create(&t, NULL, thread_func, "20") < 0){
        perror("THREAD CREATION FAILED\n");
        exit(1);
    }

    sleep(10);
    printf("Exiting main thread\n");
    pthread_exit(0);
}
