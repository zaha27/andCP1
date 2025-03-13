#ifndef INTEGRALA2_H_
#define INTEGRALA2_H_

typedef struct {
    const char *nume;
    double (*funct)(double, double, unsigned int, double (*)(double));
} MENU_ITEM;

int selecteazaOptiunea(MENU_ITEM meniu[], unsigned int nf);
double integralaSimpson(double a, double b, unsigned int n, double (*pf)(double));
double integralaTrapez(double a, double b, unsigned int n, double (*pf)(double));
double oaltafunctie(double x);

#endif
