#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    unsigned char buffer[20];
    ssize_t nr;

    char filename[100];
    scanf("%99s", filename);

    int fisierNou = open(filename, O_WRONLY | O_RDONLY | O_CREAT | O_TRUNC, 0644);
    if (fisierNou == -1) {
        perror("Eroare la crearea fisierului");
        exit(EXIT_FAILURE);
    }

    for(int i = 1; i < argc; ++i) {
        fd = open(argv[i], O_RDONLY | O_FSYNC);
        if (fd == -1) {
            perror(argv[i]);
            exit(EXIT_FAILURE);
        }
        while ((nr = read(fd, buffer, 20)) > 0) {
            write(fisierNou, buffer, nr);
        }
    }
    
    close(fd);

    return 0;
}
