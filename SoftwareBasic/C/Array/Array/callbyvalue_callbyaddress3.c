#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void addNumber(int* p1, double* p2, int increase);

int main()
{
	int integer, num;
	double dou;

	//입력 받기
	printf("정수 입력 : ");
	if (scanf("%d", &integer) != 1)
	{
		printf("정수를 입력하세요\n");
		return 1;
	}

	printf("실수 입력 : ");
	if (scanf("%lf", &dou) != 1)
	{
		printf("실수를 입력하세요\n");
		return 1;
	}

	printf("더할 정수 입력 : ");
	if (scanf("%d", &num) != 1)
	{
		printf("정수를 입력하세요\n");
		return 1;
	}

	addNumber(&integer, &dou, num);
	printf("%d가 더해진 정수 : %d, 실수 : %f\n", num, integer, dou);

	return 0;
}

void addNumber(int* p1, double* p2, int increase)
{
	*p1 += increase;
	*p2 += increase;
}