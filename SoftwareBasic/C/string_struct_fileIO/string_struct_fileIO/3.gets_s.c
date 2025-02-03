#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[10];		// 크기 10짜리 버퍼 
	printf("문자열 입력: ");

	if (gets_s(str, sizeof(str)) != NULL) {
		printf("입력한 문자열 : %s\n", str);
	}
	else {
		printf("버퍼 오버플로우\n");
		clearerr(stdin);		//입력 스트림 상태 초기화 
	}

	return 0;
}