/*
	정수를 입력 받아 짝수인지 홀수인지 판별하시오.
	예) 정수 입력 : 86(입력)
		86는(은) 짝수 입니다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t5()
{
	int num;
	printf("정수 입력 : ");
	if (scanf("%d", &num) != 1)
	{
		printf("입력 오류\n");
		return 1;
	}

	if (num % 2 == 0)
		printf("%d는(은) 짝수 입니다.\n", num);
	else 
		printf("%d는(은) 홀수 입니다.\n", num);
	return 0;
}