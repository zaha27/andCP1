#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "operatii.h"

double** citire(int n, int m) {
    double** a = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        a[i] = (double*)malloc(m * sizeof(double));
        printf("Vectorul [%d]\n", (i + 1));
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    return a;
}

double (*meniu(int optiune, double (*pf1)(int, int, double *[]), double (*pf2)(int, int, double *[]), double (*pf3)(int, int, double *[])))(int, int, double*[]) {
    switch (optiune) {
        case 1: return pf1;
        case 2: return pf2;
        case 3: return pf3;
        default:
            printf("Optiune invalida! Reincearca.\n");
            scanf("%d", &optiune);
            return meniu(optiune, pf1, pf2, pf3);
    }
}

double normaUnu(int n, int m, double *a[]) {
    double maxim = 0;
    for (int j = 0; j < m; j++) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += fabs(a[i][j]);
        }
        if (sum > maxim) {
            maxim = sum;
        }
    }
    return maxim;
}

double normaInfinit(int n, int m, double *a[]) {
    double maxim = 0;
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) {
            sum += fabs(a[i][j]);
        }
        if (sum > maxim) {
            maxim = sum;
        }
    }
    return maxim;
}

double normaDoi(int n, int m, double *a[]) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += a[i][j] * a[i][j];
        }
    }
    return sqrt(sum);
}

void eliberareMemorie(double** a, int n) {
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}
