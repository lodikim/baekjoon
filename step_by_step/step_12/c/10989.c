#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    // 1. 카운팅 배열 선언/초기화
    int counting[10001];
    for(int i=0; i<10001; i++){
        counting[i] = 0;
    }

    // 2. 카운팅 정렬 (입력)
    for(int i=0; i<N; i++){
        int input;
        scanf("%d", &input);
        counting[input]++;
    }

    // 3. 카운팅 정렬 (출력)
    for(int i=0; i<10001; i++){
        // counting[i] 횟수만큼 i 출력
        for(int j=0; j<counting[i]; j++){   
            printf("%d\n", i);
        }
    }
}