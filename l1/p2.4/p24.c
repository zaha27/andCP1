#include <stdio.h>
#include "operatii.h"

int main() {
    int n = 100;
    double rezultat1, rezultat2, rezultat3;
    printf("Integrala\tMetoda trapezelor\tMetoda dreptunghiurilor\tMetoda Simpson\n");
    rezultat1 = integralaTrapez(1, 0, n, i);
    rezultat2 = integralaDreptunghi(1, 0, n, i);
    rezultat3 = integralaSimpson(1, 0, n, i);
    printf("I1\t\t%lf\t\t%lf\t\t%lf\n", rezultat1, rezultat2, rezultat3);
    rezultat1 = integralaTrapez(3, 1, n, ii);
    rezultat2 = integralaDreptunghi(3, 1, n, ii);
    rezultat3 = integralaSimpson(3, 1, n, ii);
    printf("I2\t\t%lf\t\t%lf\t\t%lf\n", rezultat1, rezultat2, rezultat3);
    rezultat1 = integralaTrapez(3, 0, n, iii);
    rezultat2 = integralaDreptunghi(3, 0, n, iii);
    rezultat3 = integralaSimpson(3, 0, n, iii);
    printf("I3\t\t%lf\t\t%lf\t\t%lf\n", rezultat1, rezultat2, rezultat3);
    rezultat1 = integralaTrapez(4, 1, n, iv);
    rezultat2 = integralaDreptunghi(4, 1, n, iv);
    rezultat3 = integralaSimpson(4, 1, n, iv);
    printf("I4\t\t%lf\t\t%lf\t\t%lf\n", rezultat1, rezultat2, rezultat3);
    rezultat1 = integralaTrapez(5, 1, n, v);
    rezultat2 = integralaDreptunghi(5, 1, n, v);
    rezultat3 = integralaSimpson(5, 1, n, v);
    printf("I2\t\t%lf\t\t%lf\t\t%lf\n", rezultat1, rezultat2, rezultat3);

    return 0;

}