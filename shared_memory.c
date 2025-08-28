/* SHARED MEMORY */
// Some portion of the RAM is mapped common between multiple processes is called as shared memory.
// In virtual memory of the process some portion is mapped to shared memory whatever we write onto that memory will be reflected in the shared memory.
// This  will  help in inter process communication.

/* steps to create shared memory */
// create shared memory intial it will be zero byte
// assign size to the memory
// map that to the required processes.

/* Shared memory system calls */
// we can see shared memory entry in /dev/shm
// shared memory is the fasted IPC available.


/* THIS IS THE WRITE PROGRAM TO SHARED MEMORY */

#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char**argv){
    int fd;
    size_t size;
    char* addr;

    // open shared memory if it is already there or create new one
    fd = shm_open("/shm1", O_RDWR | O_CREAT, 0666);

    if (fd == -1){
        perror("shared memory creation failed");
        exit(-1);
    }

    // assign the size;
    size = strlen(argv[1]);

    if (ftruncate(fd, size) == -1){
        perror("FTRUNCATE FAILED\n");
        exit(-1);
    }

    // get address from virtual memory of the processess using mmap
    addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if(addr == MAP_FAILED){
        perror("mapping to virtual memory failed\n");
        exit(-1);
    }

    memcpy(addr, argv[1], size);
    printf("WRITTEN DATA TO SHARED MEMORY : %s\n", argv[1]);
    return 0;
}

/* THIS IS THE READ PROGRAM FROM SHARED MEMORY */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int fd;
    struct stat len;
    char* addr;

    fd = shm_open("shm1", O_RDWR, 0666);

    if (fd == -1){
        perror("FAILED TO OPEN SHARED MEMORY\n");
        exit(-1);
    }

    fstat(fd, &len);

    // mapping to virtual memory
    addr = mmap(NULL, len.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    printf("DATE PRESENT IN THE SHARED MEMORY IS %s\n", addr);

    return 0;
}




