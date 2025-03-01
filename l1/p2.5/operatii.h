#ifndef OPERATII_H_
#define OPERATII_H_

#include <math.h>

double** citire(int n, int m);
double (*meniu(int optiune, double (*pf1)(int, int, double *[]), double (*pf2)(int, int, double *[]), double (*pf3)(int, int, double *[])))(int, int, double*[]);
double normaUnu(int n, int m, double *a[]);
double normaInfinit(int n, int m, double *a[]);
double normaDoi(int n, int m, double *a[]);
void eliberareMemorie(double** a, int n);

#endif
