#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <sys/wait.h>
#include <unistd.h>

char **environ;

void run_child(const char *program_name, const char *input_file) {
    pid_t pid;
    //char *argv[] = { (char *)program_name, NULL };
    char *argv[] = { (char *)program_name, input_file, NULL };

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
        if(exit_code == 9) {
            printf("eroare la deschiderea fisierului");
        } else if(exit_code == 8) {
            printf("utilizare: %s nume_fisier\n", argv[0]);
        } else if(exit_code == 7) {
            printf("utilizare: %s fisier_intrare\n", argv[0]);
        } else if(exit_code == 6) {
            printf("dimensiune vector invalida\n");
        } else if(exit_code == 5) {
            printf("dimensiuni invalide\n");
        } else if(exit_code == 4) {
            printf("eroare la alocarea memoriei\n");
        } else {
            printf("Procesul %s s a incheiat cu codul: %d\n", program_name, exit_code);
        } 
    }
}

int main(void) {

    int n = 0;
    printf("Optiuni: 1 sau 2: \n\t");
    scanf("%d", &n);

    if(n != 1 && n !=2) {
        printf("Optiune invalida");
        exit(1);
    }

    printf("nume fisier date intrare: \n\t");
    char input_file[255];
    scanf("%255s", input_file);


    if(n == 1) {
        run_child("./child_one", input_file);
    } else {
        run_child("./child_two", input_file);
    }
    return 0;
}
