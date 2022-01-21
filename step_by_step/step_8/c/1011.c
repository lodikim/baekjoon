#include <stdio.h>
#include <math.h>

int main(void){
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        int x, y; // 조건에 의해 2^31보다 작으므로 'int'로 표현 가능
        scanf("%d %d", &x, &y);

        int distance = y-x; //distance>1
        int n = (int) sqrt((double) distance); // sqrt: input/output 모두 double

        // 이 시점에서, n^2 <= distance < (n+1)^2
        // 1. distance = n^2 이면 n+(n-1)회
        // 2. n^2 < distance <= n*(n+1) 이면 2n회
        // 3. n*(n+1) < distance < (n+1)^2 이면 (n+1)+n회
        int num;
        if(distance == n*n){
            num = n+(n-1);
        }
        else if(distance <= n*(n+1))
            num = 2*n;
        else
            num = (n+1)+n;
        printf("%d\n", num);
    }
}