#include <stdio.h>
#include <string.h> // strlen의 이용을 위해

int main(void){
    int N;
    scanf("%d\n", &N);

    for(int i=0; i<N; i++){
        char quiz[80]; // 0보다 크고 80보다 작은 문자열
        scanf("%s", quiz); // array names are pointers
        int test_len = strlen(quiz); // sizeof quiz : 80, strlen(quiz) : 문자열의 실제 길이

        int score[test_len];
        for (int j=0; j<test_len; j++){
            if(quiz[j]=='O'){ // 'O'일 경우, 앞의 것을 확인
                if(j>=1 && quiz[j-1]=='O'){
                    score[j]=score[j-1]+1;
                }
                else{
                    score[j]=1;
                }
            }
            else{ //'X'일 경우, score에 0 저장
                score[j]=0;
            }
            //printf("%d\n", score[j]);
        }

        int sum=0;
        for(int k=0; k<test_len; k++){
            sum=sum+score[k];
        }
        printf("%d\n", sum);
    }
}