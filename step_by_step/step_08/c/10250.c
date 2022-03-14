#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        int H, W, N;
        scanf("%d %d %d", &H, &W, &N);

        int X; //엘리베이터에서부터 세었을 때의 번호
        int Y; //층수
        if(N%H!=0){
            Y = N%H;
            X = N/H + 1;
        }
        else{
            Y = H;
            X = N/H;
        }

        if(X<10){
            printf("%d0%d\n", Y, X);
        }
        else{
            printf("%d%d\n", Y, X);
        }
    }
}