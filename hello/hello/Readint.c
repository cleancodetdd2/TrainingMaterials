#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)
{
	int n;
	/*
		scanf()함수를 이용해서 정수를 입력받음
		입력을 저장할 변수 n의 주소를 전달
		=> scanf()가 실행되면 n은 입력한 정수값을 가짐 
	*/
	if (scanf("%d", &n) != 1) {
		printf("입력 오류\n");
		return 1;
	}
	printf("n = %d\n", n);
	return 0;
}