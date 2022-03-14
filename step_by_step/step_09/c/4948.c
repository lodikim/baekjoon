#include <stdio.h>
#include <math.h>

void find_prime(int * prime_numbers, int size);

int main(void){
    // 시간 초과 -> 최댓값 123456*2에 대해 prime_numbers 한 번만 실행
    // 에라토스테네스의 체 이용
    int max = 123456*2;
    int prime_numbers[max];
    for(int num=0; num<max; num++){
        prime_numbers[num] = num+1;
    }
    find_prime(prime_numbers, max);

    while(1){
        int n;
        scanf("%d", &n);
        if(n==0)
            break;
    
        int count = 0;
        for(int i=n; i<=2*n-1; i++){ //숫자 n은 prime_numbers[n-1]에 위치
            if(prime_numbers[i]!=0){
                //printf("prime: %d\n", prime_numbers[i]);
                count++;
            }
        }
        printf("%d\n", count);
    }
}

// 소수들의 배열 반환 함수
void find_prime(int * prime_numbers, int size){
    int max_factor = (int) sqrt((double) size);
    //printf("max factor: %d\n", max_factor);
    prime_numbers[0]=0; //prime_numbers[0]은 1로, 소수가 아니므로
    for(int i=2; i<=max_factor; i++){
        for(int j=0; j<size; j++){
            if(prime_numbers[j]!=0){
                if(prime_numbers[j]==i){
                    //소수 (i가 소수가 아닐 경우, 이미 0으로 바뀜)
                    continue;
                }
                if(prime_numbers[j]%i==0){
                    //printf("Not prime: %d\n", prime_numbers[j]);
                    prime_numbers[j]=0;
                }
            }
        }
    }
}