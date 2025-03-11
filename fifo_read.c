#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
    int fd;

    fd = open("/tmp/myfifo", O_RDONLY);
    char buff[80];
    while(1){
        read(fd, buff, 80);
        printf("Read: %s\n", buff);
    }

    return 0;
}
