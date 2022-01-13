#include <stdio.h>

int main(void){
    char input[7];
    scanf("%[^\n]s", input);

    for(int i=0; i<3; i++){
        // i==0: left=2, right=6
        // i==1: left=1, right=5
        // i==2: left=0, right=4
        int left = 2-i;
        int right = 6-i;
        if(input[left] > input[right]){
            //print left
            for(int l=0; l<3; l++){
                printf("%c", input[2-l]);
            }
            break;
        }
        else if(input[left] < input[right]){
            //print right
            for(int r=0; r<3; r++){
                printf("%c", input[6-r]);
            }
            break;
        }
        else{
            continue;
        }
    }
}