#include <stdio.h>

int is_right(int a, int b, int c);

int main(void){
    while(1){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(x==0 && y==0 && z==0)
            break;
        else{
            if(is_right(x,y,z))
                printf("right\n");
            else
                printf("wrong\n");
        }
    }
}

int is_right(int a, int b, int c){
    int max, num1, num2;
    if(a>=b && a>=c){ //a가 최대
        max = a;
        num1 = b;
        num2 = c;
    }
    else if(b>=c){  //b가 최대
        max = b;
        num1 = a;
        num2 = c;
    }
    else{  //c가 최대
        max = c;
        num1 = a;
        num2 = b;
    }

    if(max*max == num1*num1 + num2*num2)
        return 1;
    else
        return 0;
}