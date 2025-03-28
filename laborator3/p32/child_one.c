#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 8;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        return 9;
    }

    int n;
    if (fscanf(f, "%d", &n) != 1 || n <= 0) {
        fclose(f);
        return 6;
    }

    int *v1 = malloc(n * sizeof(int));
    int *v2 = malloc(n * sizeof(int));
    int *vsum = malloc(n * sizeof(int));

    if (!v1 || !v2 || !vsum) {
        fclose(f);
        free(v1); free(v2); free(vsum);
        return 4;
    }

    int i = 0;
    for (i = 0; i < n; ++i)
        fscanf(f, "%d", &v1[i]);
    for (i = 0; i < n; ++i)
        fscanf(f, "%d", &v2[i]);

    for (i = 0; i < n; ++i)
        vsum[i] = v1[i] + v2[i];

    printf("vectorul suma: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", vsum[i]);
    printf("\n");

    fclose(f);
    free(v1);
    free(v2);
    free(vsum);

    return 0;
}
