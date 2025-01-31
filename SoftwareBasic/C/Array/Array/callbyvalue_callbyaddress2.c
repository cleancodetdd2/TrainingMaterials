#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void toUpperCase(char* p);

int main()
{
	char ch;	//입력받을 한 글자
	printf("알파벳 소문자 입력 : ");

	if (scanf("%c", &ch) != 1)
	{
		printf("입력 오류입니다\n");
		return 1;		//비정상 종료
	}
	while (getchar() != '\n');		//버퍼 비우기 

	toUpperCase(&ch);	//ch의 주소 전달
	printf("결과는 %c입니다.\n", ch);

	return 0;
}

void toUpperCase(char* p)
{
	if (*p >= 'a' && *p <= 'z')		//입력된 문자가 소문자인 경우
		*p -= 32;
}
