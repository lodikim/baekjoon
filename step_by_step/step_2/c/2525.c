#include <stdio.h>

int main(void){
    int A, B;
    scanf("%d %d", &A, &B);
    int C;
    scanf("%d", &C);

    if(B+C<60)
        printf("%d %d", A, B+C);
    else{   //B+C>=60
        int hour = (B+C)/60;
        int min = (B+C)%60;
        if(A+hour<24)
            printf("%d %d", A+hour, min);
        else    //A+hour>=24
            printf("%d %d", A+hour-24, min);
    }
}