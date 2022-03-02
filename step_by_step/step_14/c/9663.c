#include <stdio.h>
#include <math.h>

int N_queen(int num, int N, int * board);

int main(void){
    int N;
    scanf("%d", &N);

    int board[N];   //(i, board[i])가 queen의 위치
    for(int i=0; i<N; i++){
        board[i]=0;
    }

    printf("%d\n", N_queen(0, N, board));
}

int N_queen(int num, int N, int * board){
    if(num==N)
        return 1;
    else{
        //count: 경우의 수
        int count=0;
        //num 번째 줄에 queen 위치
        for(int i=0; i<N; i++){
            //0~num-1 번째 줄에 겹치는 queen 있는가 확인
            int overlap = 0;
            for(int j=0; j<num; j++){
                int column = board[j];  //queen의 위치: (j, column)
                if(column==i || abs(num-j)==abs(i-column)){
                    //printf("num, i, j, column: %d %d %d %d\n", num, i, j, column);
                    overlap = 1;
                    break;
                }
            }
            if(!overlap){   //겹치지 않을 경우
                //printf("queen position: %d, %d\n", num, i);
                board[num]=i;
                count += N_queen(num+1, N, board);
            }
        }
        return count;
    }
}