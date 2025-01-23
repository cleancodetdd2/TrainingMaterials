#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch;
	printf("문자 입력 :");
	if (scanf("%c", &ch) != 1)
	{
		printf("입력 오류\n");
		return 1;
	}

	if (ch >= 'a' && ch <= 'z')		// 소문자인 경우
		ch -= 32;					// 대문자로 변환

	switch (ch)
	{
	case 'A': case 'E': case 'I': case 'O': case 'U':
		printf("모음입니다.\n");
		break;
	default:
		if (ch >= 'A' && ch <= 'Z')
			printf("자음입니다.\n");
		else
			printf("알파벳이 아닙니다.\n");
	}
	return 0;
}