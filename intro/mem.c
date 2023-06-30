#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int *ptr = malloc(2*sizeof(int)); // pointer for an int, allocated memory using malloc
	if (ptr == NULL) { printf("Unable to allocate memory\n"); exit(1); } // can also use assert(p!=NULL);

	printf("(%d) address pointed to by ptr (%p)\n", getpid(), ptr); // getpid() gets us the process ID of the calling process.
	*ptr = 0; //assign int referenced to by ptr to the val of 0.
	
	while (1) {
		sleep(1);
		if (*ptr == 15) break;
		*ptr = *ptr + 3;
		printf("[%d] current value: (%d)\n", getpid(), *ptr);
	}
	printf("sizeof ptr: %ld", sizeof(ptr));
	return 0;
}

