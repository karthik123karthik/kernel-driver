// Semaphore is used to syncronize the process which is trying to access the shared resource to avoid race condition
// This is required for critical section - section where one prcess should execute.
// there are two types of semaphore named and unnamed, named semaphore can be found at /dev/shm
// semaphore is an interger that system nenver allows to go below zero
// main use of semaphore is resource pool management if we have multiple identical resource we use semaphore.

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

// CREATE NAMED SEMAPHORE

int main(){

    // create semaphore
    sem_t *sem;
    int val;

    sem = sem_open("sem1", O_CREAT | O_RDWR, 0666, 1);
    if (sem == SEM_FAILED){
        perror("FAILED TO CREATE SEMAPHORE\n");
        exit(-1);
    }

    sem_getvalue(sem, &val);
    printf("%d: semaphore value before entering critical section\n", val);

    // enter critical section
    sem_wait(sem); // if it is less than zero it will wait till sem value becomes greater than 1
    printf("PROCESS ONE STARTED TO EXECUTE THE CRITICAL SECTION\n");
    sem_getvalue(sem, &val);
    printf("%d: semaphore value after entering critical section\n", val);
    sleep(10);
    sem_post(sem);
    sem_getvalue(sem, &val);
    printf("%d: semaphore value after exiting critical section\n", val);

    return 0;
}


// USE THE CREATED SEMAPHORE

#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    sem_t *sem;
    int val;

    sem = sem_open("sem1", O_RDWR);
    if(sem == SEM_FAILED){
        perror("FAILED TO OPEN SEMAPHORE");
        exit(-1);
    }

    sem_getvalue(sem, &val);
    printf("%d : value before entering critical section\n", val);

    sem_wait(sem);
    printf("PROCESS TWO STARTED TO EXECUTE CRITICAL SECTION\n");
    sem_getvalue(sem, &val);
    printf("%d : value after entering critical section\n", val);

    sleep(10);
    sem_post(sem);
    sem_getvalue(sem, &val);
    printf("%d : value after exiting critical section\n", val);

    return 0;
}
