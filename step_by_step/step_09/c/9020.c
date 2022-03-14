#include <stdio.h>
#include <math.h>

void find_prime(int * prime_numbers, int size);

int main(void){
    int prime_numbers[10000];
    for(int index=0; index<10000; index++){
        prime_numbers[index]=index+1;
    }
    find_prime(prime_numbers, 10000); //10000까지의 소수 판별

    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int input;
        scanf("%d", &input);

        for(int j=input/2; j>=2; j--){
            int num1 = j;
            int num2 = input - j;

            if(prime_numbers[num1-1]!=0 && prime_numbers[num2-1]!=0){
                printf("%d %d\n", num1, num2);
                break;
            }
        }
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