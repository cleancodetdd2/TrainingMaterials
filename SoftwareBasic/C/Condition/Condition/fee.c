/*
*  나이를 입력 받아 60세 이상인 경우 
*  입장료를 0원으로 바꾸는 코드를 작성하시오.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int fee = 2000;
	int age;

	printf("나이 입력: ");
	if (scanf("%d", &age) != 1) {
		printf("입력이 잘못되었습니다. 프로그램을 종료합니다.\n");
		return 1;
	}

	if (age >= 60)
		fee = 0;

	printf("입장료는 %d원 입니다.\n", fee);
	return 0;
}