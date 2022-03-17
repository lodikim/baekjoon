#include <stdio.h>
#include <string.h>

int max(int a, int b);

int main(void){
    char string1 [1001];
    char string2 [1001];
    scanf("%s", &string1);
    scanf("%s", &string2);
    int string1_len = strlen(string1);
    int string2_len = strlen(string2);

    //LCS 배열: LCS[i][j]는 string1의 i번째 문자, string2의 j번째 문자에서의 LCS
    int LCS[string1_len+1][string2_len+1];
    for(int i=0; i<string1_len+1; i++){
        LCS[i][0] = 0;
    }
    for(int j=0; j<string2_len+1; j++){
        LCS[0][j] = 0;
    }
    for(int i=1; i<string1_len+1; i++){
        for(int j=1; j<string2_len+1; j++){
            if(string1[i-1] == string2[j-1]){
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }

    /*
    printf("    ");
    for(int j=0; j<string2_len+1; j++){
        printf("%c ", string2[j]);
    }
    printf("\n");
    for(int i=0; i<string1_len+1; i++){
        if(i==0)
            printf("  ");
        else
            printf("%c ", string1[i-1]);
        for(int j=0; j<string2_len+1; j++){
            printf("%d ", LCS[i][j]);
        }
        printf("\n");
    }
    */

    printf("%d\n", LCS[string1_len][string2_len]);
}

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}