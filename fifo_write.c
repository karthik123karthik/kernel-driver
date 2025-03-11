#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int fd;
    // fifo is also called as named pipe and it is a special file that is used to communicate between processes
    // It is a method of inter-process communication (IPC)
    char* fifo = "/tmp/myfifo";
    mkfifo(fifo, 0666); // 0666 is the permission for the fifo file

    char buff[80];

    fd = open(fifo, O_WRONLY);
    while(1){
        scanf("%s", buff);
        printf("please enter the message you want other process to known : \n");
        write(fd, buff, 80);
    }

    return 0;
}
