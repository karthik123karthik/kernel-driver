#include<stdio.h>

int main(int argc, char* argv[]){
    // print all command line args that you will receive
    for(int i=0; i<=argc; i++){
        printf("Argument %d : %s\n", i, argv[i]);
    }
    return 0;
}
