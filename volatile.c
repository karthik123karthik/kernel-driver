#include <stdio.h>

int main() {
    int volatile cnt = 0; // Now cnt is stored on the stack and not optimized away
    // everytime value is read from it's memory location

    /* assemble code difference between int cnt = 0 and int volatile cnt = 0 is
        movl $0, -4(%rbp)      # cnt at -4(%rbp) // volatile
        vs
        movl $0, %eax          # cnt in %eax   // non-volatile see here value is getting stored in eax register
        // so no need to store in stack memory
    */

    // Mainly used in embedded programming where hardware registers are mapped to memory locations
    // and their values can change outside the program's control
    printf("Hello, World!\n");
    return 0;
}
