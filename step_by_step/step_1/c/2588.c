#include <stdio.h>

int main(void){
    int A, B;
    scanf("%d %d", &A, &B);

    int line3 = A * (B % 10);
    int line4 = A * ((B / 10) % 10);
    int line5 = A * (B / 100);
    int line6 = line3 + (line4*10) + (line5*100);

    printf("%d\n", line3);
    printf("%d\n", line4);
    printf("%d\n", line5);
    printf("%d\n", line6);
    return 0;
}