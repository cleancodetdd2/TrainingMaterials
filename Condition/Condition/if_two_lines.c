#include <stdio.h>

int main_t2()
{
	int num1 = 5;

	if (num1 == 10)			
		printf("10입니다.\n");		//if에서 중괄호를 생략하면 첫번째 줄만 실행됨
		printf("if 조건문 중괄호 생략.\n");    //if의 결과와는 관계 없이 항상 실행됨

	return 0;
}