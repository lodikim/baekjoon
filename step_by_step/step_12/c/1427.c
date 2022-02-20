#include <stdio.h>
#include <string.h>

int main(void){
    char N[11]; // N은 1,000,000,000 보다 작거나 같음
    scanf("%s", N);
    
    int length = strlen(N);
    int counting[10];
    for(int i=0; i<10; i++){
        counting[i]=0;
    }
    for(int i=0; i<length; i++){
        counting[N[i]-'0']++;
    }

    for(int i=9; i>=0; i--){
        for(int j=0; j<counting[i]; j++){
            printf("%d", i);
        }
    }
}