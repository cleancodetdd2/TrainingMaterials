#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
*	나이 입력 : 
*   만약에 65세 이상인 경우 0원입니다.
	자이아드롭 입장료는 2500원 입니다.

	예)
		나이입력 : 30 (입력)
		자이아드롭 입장료는 2500원 입니다.

		나이입력 : 65 (입력)
		자이아드롭 입장료는 0원 입니다.
*/

int main()
{
	int entrance_fee = 2500;
	int age;

	printf("나이입력 : ");
	if (scanf("%d", &age) != 1)
	{
		printf("입력이 잘못되었습니다. 프로그램을 종료하겠습니다.\n");
		return 1;
	}

	if (age >= 65)
		entrance_fee = 0;

	printf("자이아드롭 입장료는 %d원 입니다.\n", entrance_fee);

	return 0;
}