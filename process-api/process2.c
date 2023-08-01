#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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
        printf("I am child (PID %d)\n", (int) getpid());
    } else {
        // parent jumps here;
        int return_code_wait = wait(NULL);  // if wstatus is not NULL then return code can be inspected: https://man7.org/linux/man-pages/man2/wait.2.html
        printf("I am parent (PID %d) of child %d return_code_wait: %d\n", (int) getpid(), return_code, return_code_wait);  // rc wait points to child pid!
    }
    return 0;
}
