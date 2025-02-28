#ifndef OPERATII_H_
#define OPERATII_H_

//metode
double integralaSimpson(double a, double b, unsigned int n, double (*pf)(double));
double integralaTrapez(double a, double b, unsigned int n, double (*pf)(double));
double integralaDreptunghi(double a, double b, int n);

//functii
double i(int);
double ii(int);
double iii(int);
double iv(int);
double v(int);

#endif