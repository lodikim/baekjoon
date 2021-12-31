#include <stdio.h>

int main(void){
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    
    int product = A*B*C;
    int digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(product>0){
        int digit = product%10;
        digits[digit] = digits[digit] + 1;
        product = product / 10;
    }

    for(int i=0; i<10; i++){
        printf("%d\n", digits[i]);
    }
}