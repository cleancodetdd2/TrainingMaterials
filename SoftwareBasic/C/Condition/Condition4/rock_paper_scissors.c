#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t2()
{
	int num;
	printf("정수 입력: ");
	if (scanf("%d", &num) != 1)
	{
		printf("입력 오류가 발생했습니다.");
		return 1;
	}
	

	/*if (num == 1)
	{
		printf("1은 가위입니다.");
	}
	else if (num == 2)
	{
		printf("2는 바위입니다.");
	}
	else if (num == 3)
	{
		printf("3은 보입니다.");
	}
	else {
		printf("오류");
	}
	*/

	switch (num)		//변수
	{
	case 1:				//값
		printf("1은 가위입니다.");
		//break;
	case 2:
		printf("2는 바위입니다.");
		//break;
	case 3:
		printf("3은 보입니다.");
		//break;
	default:
		printf("오류");
	}
	return 0;
}