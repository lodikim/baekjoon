#include <stdio.h>
#include <string.h> //header file for 'memset'

int main(void){
    int remainders[42];
    memset(remainders, 0, sizeof remainders); //모든 값을 0으로 초기화

    for(int i=0; i<10; i++){
        int num;
        scanf("%d", &num);
        remainders[num%42] = remainders[num%42]+1;
    }

    int counter = 0;
    for(int j=0; j<42; j++){
        if(remainders[j] != 0)
            counter++;
    }
    printf("%d\n", counter);
}