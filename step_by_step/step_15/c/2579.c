#include <stdio.h>

int max(int a, int b);

int main(void){
    int N;  //계단 수
    scanf("%d", &N);

    int stairs[N];
    for(int i=0; i<N; i++){
        scanf("%d", &stairs[i]);
    }

    //score[i][0]: 바로 전 계단을 밟았을 때, i+1번째 게단에서 얻을 수 있는 최대 점수
    //score[i][1]: 바로 전 계단을 건너뛰었을 때, i+1번째 게단에서 얻을 수 있는 최대 점수
    //score[n+2][0] = score[n+1][1] + stairs[n+2]
    //score[n+2][1] = max(score[n][0], score[n][1]) + stairs[n+2]
    //최종 답: max(score[N-1][0], score[N-1][1])

    int score[N][2];
    score[0][0] = stairs[0], score[0][1] = stairs[0];
    score[1][0] = stairs[0] + stairs[1], score[1][1] = stairs[1];
    //printf("stair 1: %d\nstair 2: %d\n", max(score[0][0], score[0][1]), max(score[1][0], score[1][1]));

    for(int i=2; i<N; i++){
        score[i][0] = score[i-1][1] + stairs[i];
        score[i][1] = max(score[i-2][0], score[i-2][1]) + stairs[i];
        //printf("stair %d: %d\n", i+1, max(score[i][0], score[i][1]));
    }

    printf("%d\n", max(score[N-1][0], score[N-1][1]));
}

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}