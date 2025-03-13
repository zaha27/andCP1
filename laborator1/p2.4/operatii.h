#ifndef OPERATII_H_
#define OPERATII_H_

//metode
double integralaSimpson(double a, double b, unsigned int n, double (*pf)(double));
double integralaTrapez(double a, double b, unsigned int n, double (*pf)(double));
double integralaDreptunghi(double a, double b, int n, double (*pf)(double));

//functii
double i(double);
double ii(double);
double iii(double);
double iv(double);
double v(double);

#endif