#include <stdio.h>
#include <stdlib.h>

int main(){
    // assign 10bytes of dynamic memory
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
