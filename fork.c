#include <stdio.h>
#include <unistd.h>

int global_data = 10;
int main(){
    // fork() system call is used to create a new process
    // The new process created by fork() is called child process
    // parent and child process will have seperate virtual memory

    pid_t child;
    int local_data = 20;

    switch(child = fork()){
        case -1:
            printf("Fork failed\n");
            break;
        case 0:
            global_data++;
            local_data++;
            printf("Child process : PID=%d, ParentId=%d\n", getpid(), getppid());
            printf("Child process : global_data=%d, local_data=%d\n", global_data, local_data);
            break;
        default:
            printf("Parent process: PID=%d, childId=%d\n", getpid(), child);
            printf("Parent process : global_data=%d, local_data=%d\n", global_data, local_data);
            break;
    }

    return 0;
}
