#include <stdio.h>

int max(int a, int b);

int main(void){
    int n;
    scanf("%d", &n);

    int triangle[n][n]; //정수 삼각형: triangle[i][j] ->  triangle[i+1][j] or triangle[i+1][j+1]
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            scanf("%d", &triangle[i][j]);
        }
    }

    int path[n][n]; //경로의 최대 합: path[i][j]는 i번째 줄 j번째 숫자까지의 최대 합 경로
    path[0][0] = triangle[0][0];
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j==0)   //줄의 첫 숫자일 경우
                path[i][j] = path[i-1][j] + triangle[i][j];
            else if(j==i)  //줄의 마지막 숫자일 경우
                path[i][j] = path[i-1][j-1] + triangle[i][j];
            else
                path[i][j] = max(path[i-1][j-1], path[i-1][j]) + triangle[i][j];
        }
    }
    
    //마지막 줄 최대 경로의 합
    int max=0;
    for(int i=0; i<n; i++){
        //printf("%d ", path[n-1][i]);
        if(path[n-1][i]>max)
            max = path[n-1][i];
    }
    //printf("\n");
    printf("%d\n", max);
}

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}