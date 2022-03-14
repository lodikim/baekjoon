#include <stdio.h>
#include <stdbool.h>

// 1. 한수를 판별하는 함수
bool hansu(int n){
    if(n<10){
        return true;
    }
    else{
        int common_diff = (n/10)%10 - n%10;
        while(n/10>0){
            int digit_diff = (n/10)%10 - n%10;
            if(common_diff!=digit_diff)
                return false;
            n = n/10;
        }
        return true;
    }
}

// 2. 1~N 까지의 수 중, 한수의 개수를 구한다.
int main(void){
    int N;
    scanf("%d", &N);

    int counter = 0;
    for(int i=1; i<=N; i++){
        if(hansu(i))
            counter++;
    }
    printf("%d\n", counter);
}