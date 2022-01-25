#include <stdio.h>
#include <math.h>

int main(void){
    int M, N;
    scanf("%d %d", &M, &N);

    //시간 초과 -> 에라토스테네스의 체 이용
    int prime_numbers[N-M+1];
    for(int num=0; num<N-M+1; num++){
        prime_numbers[num] = M+num;
    }

    int max_factor = (int) sqrt((double) N);
    for(int i=2; i<=max_factor; i++){
        for(int j=0; j<N-M+1; j++){
            if(prime_numbers[j]!=0){
                if(prime_numbers[j]==i){
                    // 소수 (소수가 아닐 경우, 이미 0으로 바뀜)
                    continue;
                }
                if(prime_numbers[j]%i==0){
                    //printf("Not prime: %d\n", prime_numbers[j]);
                    prime_numbers[j]=0;
                }
            }
        }
    }
    if(prime_numbers[0]==1){
        prime_numbers[0]=0;
    }

    for(int k=0; k<N-M+1; k++){
        if(prime_numbers[k]!=0){
            printf("%d\n", prime_numbers[k]);
        }
    }
}