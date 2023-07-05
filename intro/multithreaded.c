#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../utils/common.h"
#include "../utils/common_threads.h"

volatile int counter = 0; 
/* volatile here is a qualifier like `const`.
Instructs the compiler to avoid optimization w.r.t. memory-- allows multithreaded access without runtime issues? */
int loops;

void *worker (void *arg) { // worker will be executed by multiple threads in our program.
	int i;
	for (i=0; i < loops; i++) {
		counter++;	
        // printf("PID: %d\n", getpid()); // should point to same process ID for both threads.
	}
	return NULL;
}

int main (int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage: threads <value>\n");
		exit(1);
	}
	loops = atoi(argv[1]);  // atoi converts char ptr to int.
	pthread_t p1, p2; // process thread type
	printf("Initial value of counter: %d\n", counter);

	Pthread_create(&p1, NULL, worker, NULL); // create a thread using thread p1 (by ref) with start routine *worker
	Pthread_create(&p2, NULL, worker, NULL); // create a thread using thread p2 (by ref) with start routine *worker

	Pthread_join(p1, NULL); // Suspend execution of the calling thread until p1 exits.
	Pthread_join(p2, NULL); // Suspend execution of the calling thread until p2 exits.

	printf("Final value of counter: %d\n", counter);
	return 0; // success return code.

}

