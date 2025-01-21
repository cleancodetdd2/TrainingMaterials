/*
*	분 입력: 90 (입력)
*   90분은 1시간 30분입니다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	const int MINUTE_PER_HOUR = 60;
	int minute;
	printf("분 입력: ");

	if (scanf("%d", &minute) != 1) {
		printf("입력 오류입니다.\n");
		return 1;
	}

	// 90분을 1시간(60분)으로 나누면 몫이 1시간, 나머지가 30분
	printf("%d분은 %d시간 %d분 입니다.\n", 
		minute, minute / MINUTE_PER_HOUR, minute % MINUTE_PER_HOUR);
	return 0;
}