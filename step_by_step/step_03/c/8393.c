#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);

    int sum = 0; // 0으로 선언
    for(int i=1; i<n+1; i++){
        sum += i;
    }
    printf("%d\n", sum);
}