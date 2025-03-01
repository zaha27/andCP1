#include <stdio.h>
#include <stdlib.h>
#include "operatii.h"

int main(void) {
    int n, m, optiune;
    printf("Introduce n si m: ");
    scanf("%d %d", &n, &m);

    double** a = citire(n, m);

    double (*pf1)(int, int, double*[]) = normaUnu;
    double (*pf2)(int, int, double*[]) = normaInfinit;
    double (*pf3)(int, int, double*[]) = normaDoi;

    printf("Alege o optiune din meniu:\n");
    scanf("%d", &optiune);
    double (*selected)(int, int, double*[]) = meniu(optiune, pf1, pf2, pf3);

    double rezultat = selected(n, m, a);
    printf("Rezultatul normei: %lf\n", rezultat);

    eliberareMemorie(a, n);
    return 0;
}
