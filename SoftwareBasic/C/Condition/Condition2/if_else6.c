#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char input;

	printf("소문자를 입력하세요: ");
	if (scanf("%c", &input) != 1) {
		printf("입력 오류가 발생했습니다.\n");
		return 1;	// 오류 발생시 프로그램 종료
	}

	if (input >= 'a' && input <= 'z')	//입력이 소문자인지 확인
	{
		char uppercase = input - ('a' - 'A');	// 소문자를 대문자로 변환
		printf("대문자 : %c\n", uppercase);
	}
	else 
	{
		printf("입력한 문자는 소문자가 아닙니다\n");
	}
	return 0;
}