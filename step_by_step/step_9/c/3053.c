#include <stdio.h>
#define _USE_MATH_DEFINES //M_PI 이용을 위해
#include <math.h>

int main(void){
    int R;
    scanf("%d", &R);

    // 유클리드 기하학의 원: (R^2)π
    // 택시 기하학의 원: 2(R^2) (대각선이 2R인 마름모 모양)
    printf("%f\n", (double) R*R*M_PI);
    printf("%f\n", (double) 2*R*R);
}