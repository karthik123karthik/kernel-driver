#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){
    // creating a process 
    printf("HELLO WORLD!!!!! I am new Process\n");
    fflush(stdout); // flushes the output buffer of the stream.
    // sleep is a system call that is used to suspend the execution of the calling process for a specified time.
    sleep(5); // for 5 seconds
    printf("I am the same process after 5 seconds\n");
    fflush(stdout);
    sleep(5);
    // pid may change in each run 
    printf("My PID is : %d\n", getpid());
    // parent id will be always same
    printf("My Parent PID is : %d\n", getppid());

    // STATES of a Process.
    // 1. Running
    // 2. Ready to Run in main memory
    // 3. Ready to Run in swap memory
    // 4. sleep state in main memory
    // 5. sleep state in swap memory
    // 6. blocked state in swap memory
    // 7. blocked state in main memory
    // 8. terminated

    char* buff = "MYDATA";
    // buff[0] = 'A'; // segmentation fault as string literal are stored in text segment which is read only
    printf("%s\n", buff);
    buff = (char*)malloc(20);
    strcpy(buff, "NEWDATA");
    printf("%s\n", buff);
    free(buff);
    return 0;
}
