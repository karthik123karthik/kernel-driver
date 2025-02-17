#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>

int main(){
    pid_t pid = fork();
    if(pid == 0){
        printf("Child process with parentId: %d\n", getppid());
        sleep(10);
        printf("Child process exiting with parentId: %d\n", getppid());
    }
    else{
        printf("Parent process PID:%d\n", getpid());
        printf("Parent process exiting making all child process as orphan\n");
    }
    return 0;
}



#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>

int main(){
    pid_t pid = fork();
    // In Zombie process the child will be terminated but the parent is still running and child's entry is still present in the process table
    if(pid == 0){
        printf("Child process with parentId: %d\n", getppid());
        sleep(5);
        printf("Child process exiting with parentId: %d\n", getppid());
    }
    else{
        printf("Parent process PID:%d\n", getpid());
        sleep(20);
        wait(NULL);
        // to check the entry in process table we can run ps aux | grep Z
        printf("Parent process exiting\n");
    }
    return 0;
}
