#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <sys/wait.h>
#include <unistd.h>

char **environ;

void run_child(const char *program_name) {
    pid_t pid;
    char *argv[] = { (char *)program_name, NULL };

    int status;

    if (posix_spawnp(&pid, program_name, NULL, NULL, argv, environ) != 0) {
        perror("Eroare la posix_spawnp");
        exit(EXIT_FAILURE);
    }

    if (waitpid(pid, &status, 0) == -1) {
        perror("Eroare la waitpid");
        exit(EXIT_FAILURE);
    }

    if (WIFEXITED(status)) {
        int exit_code = WEXITSTATUS(status);
        printf("Procesul %s s a incheiat cu codul: %d\n", program_name, exit_code);
    } else {
        printf("Procesul %s NU s a incheiat normal.\n", program_name);
    }
}

int main(void) {
    run_child("./child_one");
    run_child("./child_two");
    return 0;
}
