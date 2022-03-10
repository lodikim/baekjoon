#include <stdio.h>

int min(int a, int b);

int main(void){
    int N;
    scanf("%d", &N);

    int num[N+1];   //num[n]: n을 1로 만드는 데 필요한 연산의 횟수
    num[0]=0, num[1]=0;
    //printf("num[%d]: %d\nnum[%d]: %d\n", 0, num[0], 1, num[1]);

    for(int i=2; i<=N; i++){
        int minimum = num[i-1] + 1;
        if(i%3==0){
            minimum = min(minimum, num[i/3]+1);
        }
        if(i%2==0){
            minimum = min(minimum, num[i/2]+1);
        }
        num[i] = minimum;
        //printf("num[%d]: %d\n", i, num[i]);
    }

    printf("%d\n", num[N]);
}

int min(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}