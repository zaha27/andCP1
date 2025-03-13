#include <stdio.h>
//#include "header.h"

int fibo(int n) {
    int r = 0;
    if(n == 1 || n == 2){
        return 1;
    }
    r = fibo(n - 1) + fibo(n - 2);
    return r;
}


int main(void) {
  int n = 0, r = 0;
  
  printf("n = ");
  scanf("%d", &n);
  
  r = fibo(n);

  printf("r = %d", r);
  return 0;
}
