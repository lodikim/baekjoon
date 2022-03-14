#include <stdio.h>

int main(void){
    int N;
    scanf("%d\n", &N);

    char numbers[N];
    scanf("%s", numbers); // 배열의 이름은 pointer

    int sum = 0;
    for(int i=0; i<N; i++){
        int digit = numbers[i]-'0'; //숫자를 char -> int
        //printf("digit: %d\n", digit);
        sum += digit;
    }
    printf("%d\n", sum);
}