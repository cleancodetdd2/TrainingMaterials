#include <stdio.h>

int main_t2()
{
	float num = 0.1f;
	char ch = 'a';

	if (num == 0.1f)		// 실수 비교
		printf("0.1입니다.\n");

	if(ch == 'a')			// 문자 비교
		printf("a입니다.\n");

	if(ch == 97)			// 문자를 ASCII 코드로 비교
		printf("a입니다...\n");

	return 0;
}