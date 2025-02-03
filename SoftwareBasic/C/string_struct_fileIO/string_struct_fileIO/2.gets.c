#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[100];
	printf("문자열 입력 :");
	gets(str);
	printf("%s\n", str);

	return 0;
}