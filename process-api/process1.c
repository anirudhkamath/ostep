#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_var = 0;

int main(int argc, char *argv[]) {
    printf("Hi! Current PID: %d\n", (int) getpid());
    int return_code = fork();  // creates a child proc

    if (return_code < 0) {
        // failure
        fprintf(stderr, "Fork failed :(\n");
        exit(1);
    } else if (return_code == 0) {
        // success!
        // this is the child process
        for (int i=0; i<5; i++) {global_var++;}
        printf("Hi father, I am your child (PID %d)\n", (int) getpid());
    } else {
        // parent jumps here;
        for (int i=0; i<5; i++) {global_var++;}
        printf("Luke (with PID %d), I am your father (PID %d)\n", return_code, (int) getpid());
    }
    printf("Value of global var: %d\n", global_var);  // expect 10? nope! You get 5 for each process. Each process has its own copy of the address space, remember?
    printf("Address of global var: %p\n", &global_var);  // funny thing is your OS will print the same address for both addresses. The child is a copy of the parent.
    return 0;
}
