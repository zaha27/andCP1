#include <stdio.h>
#include <math.h>
#include "integrala.h"

double functie(double x) {
    return sin(exp(2 * x) + 3.0);
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

