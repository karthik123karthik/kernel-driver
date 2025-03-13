#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>

int main(){
    sem_t* sem = sem_open("sem1", O_CREAT | O_RDWR, 0644, 1);
    if(sem == SEM_FAILED){
        perror("sem_open");
        exit(1);
    }

    int val;

    sem_wait(sem);
    sem_getvalue(sem, &val);
    printf("Semaphore value: %d\n", val);
    printf("Critical section\n");
    sleep(30);
    sem_post(sem);
    sem_getvalue(sem, &val);
    printf("Semaphore value: %d\n", val);
    printf("Semaphore released\n");

    sem_unlink("sem1"); // this is to remove entry from /dev/shm
    return 0;
}
