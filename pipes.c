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
