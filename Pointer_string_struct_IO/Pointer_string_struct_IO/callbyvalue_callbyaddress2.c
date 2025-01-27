#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void toUpperCase(char* p);

int main()
{
	char ch;
	printf("알파벳 소문 입력 : ");
	if (scanf("%c", &ch) != 1) {
		printf("입력 오류입니다.\n");
		return 1;
	}
	while (getchar() != '\n');

	toUpperCase(&ch);
	printf("결과는 %c입니다.\n", ch);

	return 0;
}

void toUpperCase(char* p) {
	if (*p >= 'a' && *p <= 'z')
		*p -= 32;
}