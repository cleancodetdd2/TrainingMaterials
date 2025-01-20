#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t1()
{
	char input;
	printf("알파벳 문자를 입력하세요: ");
	if (scanf("%c", &input) != 1) {
		printf("입력 오류가 발생했습니다.\n");
		return 1;		//오류 발생시 프로그램 종료
	}

	if (input >= 'a' && input <= 'z') {  //입력이 소문자인지 확인
		char uppercase = input - ('a' - 'A');
		printf("변환된 문자: %c\n", uppercase);
	}
	else if (input >= 'A' && input <= 'Z') {  //입력이 대문자인지 확인
		char lowercase = input + ('a' - 'A');
		printf("변환된 문자: %c\n", lowercase);
	}
	else {
		printf("입력한 문자는 알파벳이 아닙니다.\n");
	}

	return 0;
}