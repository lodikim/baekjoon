#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int num[n];
    for(int i=0; i<n; i++){
        scanf("%d", &num[i]);
    }

    int consecutive_sum[n];
    consecutive_sum[0] = num[0];
    for(int i=1; i<n; i++){
        consecutive_sum[i] = num[i];
        if(consecutive_sum[i-1] > 0)
            consecutive_sum[i] += consecutive_sum[i-1];
    }

    int max = -100000000;   //최솟값: -1000 * 100000
    for(int i=0; i<n; i++){
        //printf("%d ", consecutive_sum[i]);
        if(max < consecutive_sum[i])
            max = consecutive_sum[i];
    }
    //printf("\n");
    printf("%d\n", max);
}