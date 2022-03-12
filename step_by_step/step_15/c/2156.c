#include <stdio.h>

int max(int a, int b, int c);

int main(void){
    int n;
    scanf("%d", &n);

    int wine[n+1];
    for(int i=1; i<n+1; i++){
        scanf("%d", &wine[i]);
    }

    int quantity[n+1];
    //quantity[i]: i 번째 잔까지, 마실 수 있는 최대 양
    quantity[0] = 0;
    quantity[1] = wine[1];
    //printf("%d: %d\n", 1, quantity[1]);
    if(n>=2){
        quantity[2] = wine[1]+wine[2];
        //printf("%d: %d\n", 2, quantity[2]);
    }
    for(int j=3; j<n+1; j++){
        quantity[j] = max(quantity[j-2]+wine[j], quantity[j-3]+wine[j-1]+wine[j], quantity[j-1]);
        //printf("%d: %d\n", j, quantity[j]);
    }

    printf("%d\n", quantity[n]);
}

int max(int a, int b, int c){
    if(a>b && a>c)
        return a;
    else if(b>c)
        return b;
    else
        return c;
}