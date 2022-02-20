#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    int len = N;
    int arr[len];
    for(int i=0; i<len; i++){
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    while(1){
        int swapped = 0;
        for(int i=0; i<N-1; i++){
            //i와 i+1 비교, i가 더 크다면 swap
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = 1;
            }
        }
        if(!swapped) //변한 것이 없다면 break
            break;
        N = N-1; //없어도 무관하지만, 있으면 더 효율적
    }

    // 결과 출력
    for(int i=0; i<len; i++){
        printf("%d\n", arr[i]);
    }
}