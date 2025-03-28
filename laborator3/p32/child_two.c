#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return 7;
    }

    FILE* f = fopen(argv[1], "r");
    if (!f) {
        return 9;
    }

    int m, n;
    if (fscanf(f, "%d %d", &m, &n) != 2 || m <= 0 || n <= 0) {
        fclose(f);
        return 5;
    }

    int** A = malloc(m * sizeof(int*));
    int** B = malloc(m * sizeof(int*));
    int** S = malloc(m * sizeof(int*));

    for (int i = 0; i < m; ++i) {
        A[i] = malloc(n * sizeof(int));
        B[i] = malloc(n * sizeof(int));
        S[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            fscanf(f, "%d", &A[i][j]);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            fscanf(f, "%d", &B[i][j]);

    fclose(f);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            S[i][j] = A[i][j] + B[i][j];

    printf("matricea suma este\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", S[i][j]);
        printf("\n");
    }

    for (int i = 0; i < m; ++i) {
        free(A[i]);
        free(B[i]);
        free(S[i]);
    }
    free(A);
    free(B);
    free(S);

    return 0;
}
