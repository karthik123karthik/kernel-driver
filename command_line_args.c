#include<stdio.h>

extern char** environ;
int main(int argc, char* argv[]){
    // print all command line args that you will receive
    for(int i=0; i<=argc; i++){
        printf("Argument %d : %s\n", i, argv[i]);
    }

   char** env;
    for(env=environ; *env!=NULL; env++){
        printf("%s\n", *env);
    }

    putenv("SHELL=/bin/bash");
    printf("KARTHIK G K : %s\n", getenv("SHELL"));
    return 0;
}
