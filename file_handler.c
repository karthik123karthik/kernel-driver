#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(){
// fd is called file descriptor that is a smalletst non negative number the linux will provide when we run open system call.
int fd = open("newfile.txt", O_RDONLY | O_WRONLY | O_RDWR);
if(fd == -1){
  printf("failed to open file error : %d\n", errno);
  perror("Error :");
}
else {
        printf("SUCCESSUFLLY FILE CREATED\n");
}

return 0;
}
