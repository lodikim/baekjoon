#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        int k, n;
        scanf("%d\n%d", &k, &n);
        
        // 1. 각 집 거주민 수 배열 선언/초기화
        int residents[k][n];
        for(int j1=0; j1<k; j1++){
            for(int j2=0; j2<n; j2++){
                if(j1==0){
                    residents[0][j2] = j2+1; // 0층 거주민 수 초기화
                }
                else{
                    residents[j1][j2] = 0; // 나머지 층 거주민 수 초기화
                }
            }
        }

        // 2. 반복문을 통해 각 집 거주민 수 계산
        for(int floor=1; floor<k; floor++){
            for(int num=0; num<n; num++){
                for(int prev_num=0; prev_num<=num; prev_num++){
                    residents[floor][num] += residents[floor-1][prev_num];
                }
                //printf("floor: %d, num: %d, residents: %d\n", floor, num+1, residents[floor][num]);
            }
        }

        // 3. k층 n호 거주민 수 출력
        int resident_num = 0;
        for(int count=0; count<n; count++){
            resident_num += residents[k-1][count];
        }
        printf("%d\n", resident_num);
    }
}