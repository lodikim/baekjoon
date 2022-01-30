#include <stdio.h>

int main(void){
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    int min1, min2;
    if(x < w-x)
        min1 = x;
    else
        min1 = w-x;
    
    if (y < h-y)
        min2 = y;
    else
        min2 = h-y;

    if(min1<min2)
        printf("%d\n", min1);
    else
        printf("%d\n", min2);
}