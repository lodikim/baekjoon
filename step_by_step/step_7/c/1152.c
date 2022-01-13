#include <stdio.h>
#include <string.h>

int main(void){
    char sentence[1000001];
    scanf("%[^\n]s", sentence);
    //printf("%s\n", sentence);

    int len = strlen(sentence);
    int space_cnt = 0;
    for(int i=0; i<len; i++){
        if(sentence[i] == ' '){ // c에서는 ' '가 공백
            if(i!=0 && i!=len-1)
                space_cnt++;
            if(len==1)
                space_cnt=-1; //공백만 있을 경우, '1'이 출력되지 않도록
        }
    }
    printf("%d\n", space_cnt+1);
}