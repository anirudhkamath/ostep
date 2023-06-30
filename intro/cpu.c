#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
//#include "common.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
	// check that argument is passed according to `cpu <str>`.
	if(argc != 2) {
		fprintf(stderr, "usage: cpu <string>\n");
		exit(1);
	}

	char *string = argv[1];  // get the argument to `cpu`. It is a pointer to char (array of char).
	while (1) {
		sleep(1);
		printf("%s\n", string);
	}
	// finally return 0 for success code
	return 0;
}
