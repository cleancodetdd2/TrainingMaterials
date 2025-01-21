#define _CRT_SECURE_NO_WARNINGS		// scanf 보안 경고로 인한 컴파일 에러 방지 
#include <stdio.h>

int main_t4()
{
	int count;

	if (scanf("%d", &count) != 1) {
		printf("입력 오류\n");
		return 1;
	}

	for (int i = 0; i < count; i++)
		printf("Hello C! %d\n", i);

	return 0;
}