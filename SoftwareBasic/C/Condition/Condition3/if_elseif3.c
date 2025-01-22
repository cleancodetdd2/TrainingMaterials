/*
	문자를 입력하세요:  a (입력)
	변환된 문자는 A

	문자를 입력하세요:  A (입력)
	변환된 문자는 c

	문자를 입력하세요:  ! (입력)
	입력한 문자는 알파벳이 아닙니다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t3()
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
	else if (input >= 'A' && input <= 'Z')  
	{
		char lowercase = input + ('a' - 'A');   // 대문자를 소문자로 변환
		printf("소문자 : %c\n", lowercase);
	}
	else
	{
		printf("입력한 문자는 알파벳이 아닙니다\n");
	}
	return 0;
}