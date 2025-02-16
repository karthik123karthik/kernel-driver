#include <stdio.h>
#include <stdlib.h>

int main(){
    // assign 10bytes of dynamic memory
    // internally this functions uses brk() && sbrk() system calls
    // brk() system call will point the program break of the heap to the new position
    // sbrk() system call will increment the program break pointer by the given bytes
    int* ptr = (int*)malloc(10*sizeof(int));
    if(ptr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    free(ptr);
    ptr = (int*)calloc(10, sizeof(int));

    ptr = realloc(ptr, 20*sizeof(int));

    for(int i=0; i<10; i++){
        ptr[i] = i;
    }

    for(int i=0; i<10; i++){
        printf("%d\n", ptr[i]);
    }

    free(ptr);

}
