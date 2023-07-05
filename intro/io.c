#include <stdio.h>
#include <unistd.h>  // https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html
#include <assert.h>  // https://pubs.opengroup.org/onlinepubs/007904975/basedefs/assert.h.html
#include <fcntl.h>  // file control options: https://pubs.opengroup.org/onlinepubs/000095399/basedefs/fcntl.h.html
#include <sys/types.h>  // includes definition for some data types: https://pubs.opengroup.org/onlinepubs/007904875/basedefs/sys/types.h.html
#include <string.h>

int main (int argc, char *argv[]) {
    int fd = open("/tmp/testing", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);  // returns file descriptor that refers to the a file. a file descriptor is maintained for open files by the OS to manage file access across this shared resource.
    // We open the file at /tmp/testing with the Read/Write mode, with flags to create the file if it doesn't exist, and to truncate (clear the file first before writing).

    assert(fd != -1);  // -1 is a failure code.

    char *string = "This is a test!\t Trying out different things.\n";
    int rc = write(fd, string, strlen(string));
    assert(rc==strlen(string));
    close(fd);
    return 0;

}
