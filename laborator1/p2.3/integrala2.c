#include <stdio.h>
#include <math.h>
#include "integrala2.h"

int selecteazaOptiunea(MENU_ITEM meniu[], unsigned int nf) {
    int optiune = -1;

    printf("\nMeniu:\n");
    for (unsigned int i = 0; i < nf; i++) {
        printf("%d. %s\n", i + 1, meniu[i].nume);
    }

    printf("Alege o optiune: ");
    scanf("%d", &optiune);

    if (optiune < 1 || optiune > (int)nf) {
        printf("Optiune invalida!\n");
        return -1;
    }

    return optiune - 1;
}

// Metoda Simpson
double integralaSimpson(double a, double b, unsigned int n, double (*pf)(double)) {
    if (n % 2 == 1) {
        n++; 
    }

    double h = (b - a) / n;
    double sum = pf(a) + pf(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * pf(x);
        } else {
            sum += 4 * pf(x);
        }
    }

    return (h / 3) * sum;
}

double integralaTrapez(double a, double b, unsigned int n, double (*pf)(double)) {
    double sum, x, dx, eps = 1e-4;

    dx = (b - a) / n;
    sum = ((*pf)(a) + (*pf)(b)) / 2;

    for(x = a + dx; 
        fabs(x + dx - b) > eps;
        x += dx) {
            sum += ((*pf)(x));
        }

        sum *= dx;

        return sum;
}

double oaltafunctie(double x) {
    return x * x; 
}
