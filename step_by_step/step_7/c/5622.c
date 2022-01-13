#include <stdio.h>
#include <string.h>

int main(void){
    char dial[11][5] = {"","","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

    char word[16];
    scanf("%s", word);

    int len_word = strlen(word);
    int time = 0;
    for(int i=0; i<len_word; i++){
        char letter = word[i];
        //printf("%c ", letter);
        for(int j=0; j<11; j++){
            if(strchr(dial[j], letter) != NULL){
                //printf("%d %s\n", j, dial[j]);
                time += j;
            }
        }
    }
    printf("%d\n", time);
}