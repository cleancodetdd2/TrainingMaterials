#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t1()
{
	//배열은 한 개 이상 초기화 시, 나머지 공간은 0으로 채워짐 
	int a[100] = { 0 };
	printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[99]);
	printf("\n");

	int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i, inputMonth;
	for (i = 1; i <= 12; i++)
		printf("%2d월의 날짜는 %2d일 입니다.\n", i, month[i]);

	printf("\n\n월 입력 : ");
	if (scanf("%d", &inputMonth) != 1) {
		printf("입력 오류입니다.\n");
		return 1;
	}
	printf("입력한 월의 날짜는 %d일 입니다\n", month[inputMonth]);

	return 0;
}