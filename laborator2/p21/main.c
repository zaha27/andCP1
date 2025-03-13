#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    unsigned char buffer[20];
    ssize_t nr;

    fd = open(argv[1], O_RDONLY | O_FSYNC);
    if (fd == -1) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((nr = read(fd, buffer, 20)) > 0) {
        write(1, buffer, nr);
    }

    close(fd);

    return 0;
}
