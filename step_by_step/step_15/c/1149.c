#include <stdio.h>

int min(int a, int b);

int main(void){
    // color[n][i]: n+1번째 집을 i 색깔로 칠하는 비용 (i=0: 빨강, i=1: 초록, i=2: 파랑)
    // price[n][i]: n+1번째 집을 i 색깔로 칠할 때, 1~n까지 모든 집들을 칠하는 최소 비용
    // price[n+1][0] = min(price[n][1], price[n][2]) + color[n+1][0]
    // 최종 답: price[N-1][0], price[N-1][1], price[N-1][2]의 최솟값

    int N;
    scanf("%d", &N);

    int color[N][3];
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &color[i][j]);
        }
    }

    int price[N][3];
    price[0][0] = color[0][0], price[0][1] = color[0][1], price[0][2] = color[0][2];
    //printf("price[0][0]: %d, price[0][1]: %d, price[0][2]: %d\n", price[0][0], price[0][1], price[0][2]);
    
    for(int i=1; i<N; i++){
        price[i][0] = min(price[i-1][1], price[i-1][2]) + color[i][0];
        price[i][1] = min(price[i-1][2], price[i-1][0]) + color[i][1];
        price[i][2] = min(price[i-1][0], price[i-1][1]) + color[i][2];
        //printf("price[%d][0]: %d, price[%d][1]: %d, price[%d][2]: %d\n", i, price[i][0], i, price[i][1], i, price[i][2]);
    }

    int result = min(min(price[N-1][0], price[N-1][1]), price[N-1][2]);
    printf("%d\n", result); 
}

int min(int a, int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}