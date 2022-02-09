#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

// 1. 각 학생의 덩치를 저장하는 배열을 만든다.
    int bulk [N][2];
    for(int i=0; i<N; i++){
        scanf("%d %d", &bulk[i][0], &bulk[i][1]);
    }

// 2. 각 학생의 덩치 등수를 저장하는 배열을 만든다.
    int rank [N];
    for(int i=0; i<N; i++){
        rank[i]=1;
    }

// 3. 각 학생에 대해, 덩치가 더 큰 학생의 수를 구한다.
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j==i)
                continue;
            if(bulk[j][0]>bulk[i][0] && bulk[j][1]>bulk[i][1])
                rank[i]++;
        }
    }

// 4. 배열 출력
    for(int i=0; i<N; i++){
        printf("%d ", rank[i]);
    }
}