#include <stdio.h>
#include "integrala2.h"

int main(void) {
    int n = 0;
    printf("Introduce n = ");
    scanf("%d", &n);

    MENU_ITEM meniu[] = {
        { "Calculul integralei prin metoda trapezelor", integralaTrapez },
        { "Calculul integralei prin metoda Simpson", integralaSimpson }
    };

    int optiune = selecteazaOptiunea(meniu, sizeof(meniu) / sizeof(meniu[0]));
    if (optiune == -1) {
        return 1;
    }

    double a = 2, b = 3;
    double (*pf)(double) = &oaltafunctie;

    double rezultat = meniu[optiune].funct(a, b, n, pf);

    printf("Rezultatul integralei: %lf\n", rezultat);

    return 0;
}
