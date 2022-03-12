#include <stdio.h>

int max(int a, int b);

int main(void){
    int N;
    scanf("%d", &N);
    int A[N];
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    //1. 양쪽으로 LIS의 배열 구하기
    int LIS_left[N]; //LIS_left[i]: 왼쪽부터, A[i]를 포함하는 LIS의 길이
    int LIS_right[N]; //LIS_right[i]: 오른쪽부터, A[i]를 포함하는 LIS의 길이

    LIS_left[0]=1;
    LIS_right[N-1]=1;
    for(int i=1; i<N; i++){
        LIS_left[i]=1;
        LIS_right[N-1-i]=1;
        for(int j=0; j<i; j++){
            if(A[i]>A[j])
                LIS_left[i] = max(LIS_left[i], LIS_left[j]+1);
            if(A[N-1-i]>A[N-1-j])
                LIS_right[N-1-i] = max(LIS_right[N-1-i], LIS_right[N-1-j]+1);
        }
    }
    /*
    for(int i=0; i<N; i++){
        printf("LIS_left[%d]: %d, LIS_right[%d]: %d\n", i, LIS_left[i], i, LIS_right[i]);
    }
    */


    //2. 둘을 합쳐 바이토닉 수열의 배열 구하기
    int bitonic[N];
    for(int i=0; i<N; i++){
        bitonic[i] = LIS_left[i] + LIS_right[i]-1;
        //printf("bitonic[%d]: %d\n", i, bitonic[i]);
    }

    //3. 가장 긴 바이토닉 수열의 길이 구하기
    int max=0;
    for(int i=0; i<N; i++){
        if(bitonic[i]>max)
            max = bitonic[i];
    }
    printf("%d\n", max);
}

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}