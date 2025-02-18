#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char*argv[]){
    printf("I am the Main Process which will call execl system call : %d\n", getpid());
    // execl is a sytem call that will replace the current process with a new process (virtual memory will be replaced)
    // execl("./replace_process", "ls", "-l", NULL);
    // similar to execl we have execv which takes an array of arguments
    execv("./replace_process", argv);
    // if system call is success below code will not be executed
    printf("System call ended\n");
    return 0;
}
