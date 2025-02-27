#include <stdio.h>
#include "integrala.h"

int main(void) {
    int n = 0;
    printf("introduce n = ");
    scanf("%d", &n);
    
    double (*pfct)(double);
    pfct = &functie;
    double rezultat;
    rezultat = integralaTrapez(3, 2, n, pfct);
    printf("%lf", rezultat);

    return 0;
}

