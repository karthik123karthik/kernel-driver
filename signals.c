// Signals are the software interrupts that gives a mechanism to 
// notify a process that a specific event has occurred.
// Each signal have a unique Number associated with it
// Each signal will be having default handler for eg SEGV generate core dump

//EXECVE - system call loads new program in process memory
// current process will be terminated and new process will replace virtual memory

#include <stdio.h>
#include <signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void handle_signal(int signal){
    printf("Signal caught\n %d", signal);
    exit(-1);
}

void handle_alaram(int sig){
    printf("Alarm signal caught\n");
    // overriden handler here
    signal(SIGALRM, SIG_IGN);
    alarm(2);
    exit(EXIT_SUCCESS);
}

int main(){
    // signals are the software interrupts that are sent to a process to notify that a particular event has occurred.
    // basically an asyncronous notification to a process.

    // signal() function is used to handle signals.
    printf("%d : is my processId\n", getpid());
    if(signal(SIGINT, handle_signal) == SIG_ERR){
        printf("Error in handling sigint signal\n");
    }
    if(signal(9999, handle_signal) == SIG_ERR){
        printf("Error in handling signal\n");
    }
    
    if(signal(SIGTERM, handle_signal) == SIG_ERR){
        printf("Error in handling sigterm signal\n");
    }

    if(signal(SIGALRM, handle_alaram) == SIG_ERR){
        printf("Error in handling sigalarm signal\n");
    }

    alarm(2);

    while(1);

    return 0;
}
