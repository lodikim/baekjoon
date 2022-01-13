#include <stdio.h>
#include <string.h>
#include <ctype.h> //toupper() 사용

int main(void){
    char word[1000001]; //null 문자 저장을 위해
    scanf("%s", word);

    int alphabet[26];
    for(int i=0; i<26; i++){
        alphabet[i]=0;
    }

    int len = strlen(word); //for문에 넣으면 시간 초과
    for(int j=0; j<len; j++){
        char cur = toupper(word[j]);  //모든 알파벳을 대문자로 변환
        alphabet[cur-'A']++;
    }

    int max = 0, num = 0, max_alphabet = 0; //각각 초기화 필요
    for(int k=0; k<26; k++){
        if(alphabet[k] > max){
            max = alphabet[k];
            num = 1;
            max_alphabet='A'+k;
        }
        else if(max!=0 && alphabet[k] == max){
            num++;
        }
        else{
            continue;
        }
    }
    //printf("%d %d %d\n", max, num, max_alphabet);

    if(num==1){
        printf("%c\n", max_alphabet); // implicit type conversion
    }
    else{
        printf("?");
    }
}