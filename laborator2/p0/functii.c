#include <stdio.h>
#include "header.h"


void afisare() {
    printf("abcd");
}


int fibo(int n) {
    int r = 0;
    if(n == 1 || n == 2){
        return 1;
    }
    r = fibo(n - 1) + fibo(n - 2);
    return r;
}