#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


// pipes is used for IPC - it uses byte stream 
// it is unidirectional
// fd[0] is read end and fd[1] is write end.

int main(){
    int fd[2];

    if(pipe(fd) == -1){
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();

    if(pid == 0){
        if(close(fd[1]) == -1){
            perror("write end is unused");
            exit(1);
        }
        char buff[12] = {};
        while(1){
        strcpy(buff, "");
        int res = read(fd[0], buff, sizeof(buff));
        printf("Child:  read: %d\n", res);
        if(res == -1){
            exit(1);
        }
        if(res == 0)break;
        printf("Child:  read: %s\n", buff);
        close(fd[0]);
        sleep(10);
        }
        if(close(fd[0]) == -1){
            perror("read end is unused");
            exit(1);
        }
        exit(0);

    }else{
        if(close(fd[0]) == -1){
            perror("read end is unused");
            exit(1);
        }
        printf("Parent: closing read end\n");
        char *msg = "Hello World";
        write(fd[1], msg, strlen(msg));
        while(1){
        sleep(2);
        write(fd[1], msg, strlen(msg));
        printf("Parent: wrote: %s\n", msg);
        }
        exit(0);
    }

    return 0;
}


// Pipes are one of the IPC that used stream based method.
// pipes are unidirectional
// pipes have limited size and it is a buffer stored in kernel memory
// mostly used for related processes

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int fd[2];
    char buff[20];
    size_t len;

    if(pipe(fd) == -1){
        perror("PIPE CREATION FAILED");
        exit(1);
    }
    
    switch(fork()){
        case -1:
             perror("FAILED FORK");
             exit(1);
        
        case 0:
            printf("CHILD PROCESS : pid :%d\n", getpid());
            if(close(fd[1]) == -1){
                perror("CLOSING READ END\n");
                exit(1);
            }

            read(fd[0], buff, sizeof(buff));
            printf("Read from pipe: %s\n", buff);
            break;
        
        default:
            printf("PARENT PROCESS : pid - %d\n", getpid());
            if(close(fd[0]) == -1){
                perror("CLOSING READ END\n");
                exit(1);
            }

            write(fd[1], "Hello, World!", 13);
            wait(NULL);
            break;
    }
    return 0;
}
