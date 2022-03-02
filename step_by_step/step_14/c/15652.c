#include <stdio.h>

void search(int * arr, int count, int N, int M);

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    int arr[M];
    search(arr, 0, N, M);
}

void search(int * arr, int count, int N, int M){
    if(count==M){
        //print arr
        for(int i=0; i<M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else{
        int prev = 1;
        if(count>0)
            prev = arr[count-1];

        for(int i=prev; i<=N; i++){
            arr[count] = i;
            search(arr, count+1, N, M);
        }
    }
}