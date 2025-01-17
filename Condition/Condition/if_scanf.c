#define _CRT_SECURE_NO_WARNINGS			// scanf() 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>

int main_t4()
{
	int num1;
	int result;

	result = scanf("%d", &num1);	// 입력받은 값을 num1변수에 저장
	if (result != 1)				// 입력이 제대로 되었는지 확인
	{
		printf("입력 오류\n");
		return 1;
	}

	if (num1 == 10)
		printf("10입니다.\n");
	
	if (num1 == 20)
		printf("20입니다.\n");

	return 0;
}