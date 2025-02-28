#include <stdio.h>
#include <math.h>
#include "operatii.h"

double integralaDreptunghi(double a, double b, int n, double (*pf)(double)) {
    double suma = 0.0;
    double dx = (b - a) / n;
    
    for (int i = 0; i < n; i++) {
        double x_mijloc = a + (i + 0.5) * dx; 
        suma += pf(x_mijloc);
    }
    
    return suma * dx;
}

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

double i(double x) {
    return exp(-pow(x,2));
}
double ii(double x) {
    return x;
}
double iii(double x) {
    return x * x;
}
double iv(double x) {
    return sqrt(1 + 1 / x);
}
double v(double x) {
    return (x / (1 + x));
}