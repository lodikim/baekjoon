#include <stdio.h>

int factorial(int n);

int main(void){
    int N;
    scanf("%d", &N);
    printf("%d\n", factorial(N));
}

int factorial(int n){
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}