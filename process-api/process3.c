#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
    printf("Yeah yeah I am process PID %d\n", (int) getpid());
    int return_code = fork();

    if (return_code < 0) {
        printf("Something went wrong while forking\n"); exit(1);
    } else if (return_code == 0)
    {
        // child
        printf("I am now child (PID %d), destroyer of sleep\n", (int) getpid());
        char *execargs[3];  // declaration
        // execargs[0] = strdup("wc"); // create a duplicate string at a new address-- strdup returns the pointer to the duplicated string
        execargs[0] = "wc";
        execargs[1] = "test";
        execargs[2] = NULL; // end of array

        execvp(execargs[0], execargs);
        printf("This should not be printed\n"); // does not get printed because "the calling process image is overlaid by the new process image." https://pubs.opengroup.org/onlinepubs/7908799/xsh/exec.html. Essentially what happens here is the calling process static data, runtime vars on the stack, heap data, ... are replaced with the same for the new process!
    } else {
        int return_code_wait = wait(NULL);
        printf("I am parent (PID: %d) with RC wait %d\n", (int) getpid(), return_code_wait);
    }
    return 0;
    
}
