#include <stdio.h>

int main(void){
    int A, B, V;
    scanf("%d %d %d", &A, &B, &V);

    // n일: (A-B)*(n-1) + A >= V
    //      -> n >= (V-A)/(A-B) + 1
    // 따라서 (V-A)/(A-B)가 정수일 경우 그대로 정수가 아닐경우 1을 더해줌

    int n;
    if((V-A)%(A-B)==0){
        n = (V-A)/(A-B)+1;
    }
    else{
        n = (V-A)/(A-B)+2;
    }
    printf("%d\n", n);
}