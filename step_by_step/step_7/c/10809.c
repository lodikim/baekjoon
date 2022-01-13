#include <stdio.h>
#include <string.h>

int main(void){
    char S[100];
    scanf("%s", S);

    int position[26];
    for(int i=0; i<26; i++){
        position[i] = -1;
    }

    for(int j=0; j<strlen(S); j++){
        char alphabet = S[j];
        //printf("alphabet: %c\n", alphabet);

        if(position[alphabet-'a'] == -1)
            position[alphabet-'a'] = j;
        else
            continue; //break를 쓰면 for문 종료
    }

    for(int k=0; k<26; k++){
        printf("%d ", position[k]);
    }
}