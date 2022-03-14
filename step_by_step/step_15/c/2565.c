#include <stdio.h>

void sort(int * A, int * B, int num);
int max(int a, int b);

int main(void){
    int num;
    scanf("%d", &num);

    int A[num];
    int B[num];
    for(int i=0; i<num; i++){
        scanf("%d %d", &A[i], &B[i]);
    }

    // 1. A 전봇대와 연결된 위치 오름차순 정렬
    sort(A, B, num);
    /*
    for(int i=0; i<num; i++){
        printf("%d %d\n", A[i], B[i]);
    }*/

    // 2. B 전봇대와 연결된 위치 LIS 계산
    int LIS[num]; //LIS[i]: B[i]를 포함하는 가장 긴 부분 수열의 길이
    LIS[0]=1;
    for(int i=1; i<num; i++){
        LIS[i]=1;
        for(int j=0; j<i; j++){
            if(B[i]>B[j]){
                LIS[i] = max(LIS[i], LIS[j]+1);
            }
        }
    }

    int max=0;
    for(int i=0; i<num; i++){
        if(LIS[i]>max)
            max=LIS[i];
    }

    // 3. 없애야 하는 전깃줄 개수 출력
    printf("%d\n", num-max);
}

void sort(int * A, int * B, int num){
    for(int i=0; i<num-1; i++){
        int min_index = i;
        for(int j=i+1; j<num; j++){
            if(A[j]<A[min_index]){
                min_index = j;
            }
        
            if(j==num-1){
                //swap both A and B
                int temp_A = A[min_index];
                A[min_index] = A[i];
                A[i] = temp_A;

                int temp_B = B[min_index];
                B[min_index] = B[i];
                B[i] = temp_B;
            }
        }
    }
}

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}