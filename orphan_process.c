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
