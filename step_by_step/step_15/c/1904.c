#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    //visual studio에서는 스택 사이즈 때문에 큰 수에서 에러
    int num[N]; //num[N-1] -> 길이가 N인 수열의 개수
    num[0] = 1;
    if(N>1){
        num[1] = 2;
        for(int i=2; i<N; i++){
            num[i] = (num[i-2] + num[i-1])%15746;   //마지막에 나머지를 구하면 overflow
        }
    }

    printf("%d\n", num[N-1]);
}