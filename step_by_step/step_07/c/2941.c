#include <stdio.h>
#include <string.h>

int main(void){
    char croatia_alphabet[8][4] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    char input[101];
    scanf("%s", input);
    int input_len = strlen(input);
    int count = 0; // 알파벳의 개수
    int cr_count = 0; //크로아티아 알파벳 표현에 쓰인 char 개수
// 1. 입력 문자열 중 croatia_alphabet에 있는 알파벳들 count
    for(int num=0; num<8; num++){ // 각각의 croatia alphabet
        int alphabet_len;
        if(num==2)
            alphabet_len = 3; // "dz="일 경우, 길이가 3
        else
            alphabet_len = 2;

        // 2글자(혹은 3글자)씩 croatia_alphabet인지 확인
        for(int i=0; i<=input_len-alphabet_len; i++){
            int is_croatia = 0; // 0: false, 1: true
            for(int j=0; j<alphabet_len; j++){
                if(input[i+j] != croatia_alphabet[num][j])
                    break; // 'break'는 하나의 for문만 탈출
                if(j==alphabet_len-1){
                    is_croatia = 1;
                    //printf("%s\n", croatia_alphabet[num]);
                }
            }
            
            if(is_croatia){ // croatia_alphabet이면 실행
                if(num==2){ // "dz="일 경우, 3글자이고 "z=" 에서 중복되므로 예외 처리
                    cr_count+=3; // (+) 3글자
                    cr_count-=2; // (-) 2글자
                }
                else{
                    count++;
                    cr_count+=2;
                }
            }
        }
    }

// 2. 남은 알파벳들 count
    count += input_len - cr_count;
    printf("%d\n", count);
}