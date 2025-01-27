#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a[100] = { 0 };  // 배열은 한 개 이상 초기화 시, 나머지 공간은 0으로 채워짐
	//printf("%d %d %d %d\n", a[0], a[1], a[2], a[99]);

	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int i, searchMonth;
	for (i = 1; i <= 12; i++)
		printf("%2d월의 일수는 %2d일 입니다.\n", i, month[i]);

	printf("\n\n검색 월 입력 : ");
	if (scanf("%d", &searchMonth) != 1) {
		printf("입력 오류 입니다.\n");
		return 1;
	}

	printf("검색한 월의 일수는 %2d일 입니다.\n", month[searchMonth]);

	return 0;
}