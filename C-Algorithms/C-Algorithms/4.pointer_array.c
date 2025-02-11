#include <stdio.h>

#define SIZE 2		//배열 크기 정의

//정수형 포인터 배열을 받아 출력하는 함수
void printIntArray(int* p[])
{
	printf("--------정수형 포인터 배열----------\n");
	for (int i = 0; i < SIZE; i++)
		printf("엘리먼트 %d: %d\n", i, *p[i]);
	printf("\n");
}

//실수형 포인터 배열을 받아 출력하는 함수
void printDoubleArray(double* p[])
{
	printf("--------실수형 포인터 배열----------\n");
	for (int i = 0; i < SIZE; i++)
		printf("엘리먼트 %d: %.2f\n", i, *p[i]);
	printf("\n");
}

int main()
{
	int x = 8, y = 9;				//정수 변수
	double d1 = 3.14, d2 = 5.23;	//실수 변수 

	int* pi[SIZE] = { &x, &y };		//정수형 포인터 배열 초기화
	double* pd[SIZE] = { &d1, &d2 }; //실수형 포인터 배열 초기화 

	//포인터 배열을 통해 접근한 값 출력
	printf("포인터 배열을 통해 접근한 값 : \n");
	printf("x: %d, *pi[0]: %d\n", x, *pi[0]);
	printf("y: %d, *pi[1]: %d\n", y, *pi[1]);
	printf("d1: %.2f, *pd[0]: %.2f\n", d1, *pd[0]);
	printf("d2: %.2f, *pd[1]: %.2f\n", d2, *pd[1]);

	printIntArray(pi);
	printDoubleArray(pd);

	return 0;
}