#include <stdio.h>

int diff_one(int n1, int n2, int n3);

int main(void){
    int x_arr[3];
    int y_arr[3];

    for(int i=0; i<3; i++){
        scanf("%d %d", &x_arr[i], &y_arr[i]);
    }
    int x = diff_one(x_arr[0], x_arr[1], x_arr[2]);
    int y = diff_one(y_arr[0], y_arr[1], y_arr[2]);
    printf("%d %d", x, y);
}

int diff_one(int n1, int n2, int n3){
    if(n1==n2)
        return n3;
    else{
        if(n1==n3)
            return n2;
        else
            return n1;
    }
}