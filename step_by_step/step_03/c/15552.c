#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", A+B);
    }
}

// 입력과 출력 스트림은 별개이므로,
// 테스트케이스를 전부 입력받아서 저장한 뒤 전부 출력할 필요는 없습니다.

//C언어의 경우, 사실상 10950번과 같은 문제입니다.