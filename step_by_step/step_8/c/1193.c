#include <stdio.h>

int main(void){
    /*
        X = 1 : 1/1
        X = 2 ~ 3 : 1/2 ~ 2/1
        X = 4 ~ 6 : 3/1 ~ 1/3
        X = 7 ~ 10 : 1/4 ~ 4/1
        ...
        X = 1+2+...+(n-1)+1 ~ 1+2+...+n : 1/n ~ n/1 (n: 짝수)
        X = 1+2+...+(n-1)+1 ~ 1+2+...+n : n/1 ~ 1/n (n: 홀수)
    */
    int X;
    scanf("%d", &X);

    int n=1;
    while(1){
        // X = 1+2+...+(n-1)+1 ~ 1+2+...+n -> X = (n-1)*n/2 + 1 ~ n*(n+1)/2
        if((n-1)*n/2+1<=X && X<=n*(n+1)/2){ // X의 범위 찾기
            break;
        }
        n++;
    }

    int numerator, denominator;
    if(n%2==0){ //n이 짝수
        numerator = X-(n-1)*n/2; //분자
        denominator = (n+1) - numerator; //분모
    }
    else{   //n이 홀수
        denominator = X-(n-1)*n/2; //분모
        numerator = (n+1) - denominator; //분자
    }
    printf("%d/%d", numerator, denominator);
}