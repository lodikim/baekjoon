#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    int numbers[N];
    for(int n=0; n<N; n++){
        scanf("%d", &numbers[n]);
    }

    int count=0;
    for(int i=0; i<N; i++){
        int number = numbers[i];

        // number이 소수인지 확인, 소수라면 count++
        for(int j=2; j<number; j++){ // 2는 고려하지 못함
            if(number%j==0){
                break;
            }
            if(j==number-1){
                count++;
            }
        }
        if(number==2)
            count++;
    }
    printf("%d\n", count);
}