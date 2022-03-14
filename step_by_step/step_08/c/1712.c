#include <stdio.h>

int main(void){
    int A, B, C; //32비트 부호 정수형 최댓값: 2,147,483,647
    scanf("%d %d %d", &A, &B, &C);

    if(B>=C){
        printf("-1\n"); //손익분기점 존재 X
    }
    else{
        //C>B 이므로, C-B>0
        int n = A/(C-B);
        printf("%d\n", n+1); //'이득'을 보려면 1 추가
    }
}