#include <stdio.h>

int main(void){
	int N; //N의 최댓값 10억은 int 범위 내
	scanf("%d", &N);

	/*	
		1: 1개
		2~7 (1+1 ~ 1+6): 2개
		8~19 (1+6+1 ~ 1+6+6*2): 3개
		20~37 (1+6+6*2+1 ~ 1+6+6*2+6*3): 4개
		38~61 (1+6+6*2+6*3+1 ~ 1+6+6*2+6*3+6*4): 5개
		...
		1+6+6+2+...+6*n+1 ~ 1+6+6+2+...+6*n+6*(n+1): n+2개 (n>=0)
	*/
	
	if(N==1){
		printf("1");
	}
	else{
		int n=0;
		/*
			1+6+6+2+...+6*n+1 = 2 + 3*n*(n+1)
			1+6+6+2+...+6*n+6*(n+1) = 1 + 3*(n+1)*(n+2)
		*/
		while(1){
			if(2+3*n*(n+1)<=N && N<=1+3*(n+1)*(n+2)){ // N의 범위 찾기
				break;
			}
			n++;
		}
		printf("%d", n+2);
	}
}