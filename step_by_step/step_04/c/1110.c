#include <stdio.h>

int main(void){
    int first_N, N;
    scanf("%d", &first_N);
    N = first_N;

    int cycle = 0;
    while(1){
        int digit_sum = N/10 + N%10; // N의 자릿수들의 합
        N = (N%10)*10 + digit_sum%10; // 새로운 N
        cycle++;
        
        if(first_N == N) // 반드시 while문의 마지막에 검사
            break;
    }
    printf("%d\n", cycle);
}