#include <stdio.h>

// 1. 입력된 수의 분해합을 구하는 프로그램을 작성한다.
int find_dn(int n);

int main(void){
    int N;
    scanf("%d", &N);

// 2. N 이하 모든 수의 분해합을 계산 및 비교한다.
    for(int i=1; i<=N; i++){
        if(find_dn(i) == N){
            printf("%d\n", i);
            break;
        }
        if(i==N)
            printf("0");
    }
}

int find_dn(int n){
    int dn = n;
    while(n>0){
        dn = dn + n%10;
        n = n/10;
    }
    return dn;
}