#include <stdio.h>

int hanoi(int n, int start, int end, int tag);
int other_rod(int start, int end);

int main(void){
    int N;
    scanf("%d", &N);

    int count = hanoi(N, 1, 3, 0);
    printf("%d\n", count);
    hanoi(N, 1, 3, 1);
}

int hanoi(int n, int start, int end, int tag){
    //base case
    if(n==1){
        if(tag==1){
            printf("%d %d\n", start, end);
        }
        return 1;
    }
    //recursive case
    else{
        int other = other_rod(start, end);
        int count = hanoi(n-1, start, other, tag);
        count += hanoi(1, start, end, tag);
        count += hanoi(n-1, other, end, tag);
        return count;
    }
}

int other_rod(int start, int end){
    if(start!=1 && end!=1)
        return 1;
    else if(start!=2 && end!=2)
        return 2;
    else
        return 3;
}