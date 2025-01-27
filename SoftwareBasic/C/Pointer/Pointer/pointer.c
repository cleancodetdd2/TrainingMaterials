#include <stdio.h>

int main_t2()
{
	int* numPtr;			// 포인터 변수 선언
	int num = 10;			// int형 변수 선언하고 초기화

	numPtr = &num;			// num의 메모리 주소를 포인터 변수에 저장

	printf("%p\n", numPtr);		// 포인터 변수 numPtr의 값 출력

	printf("%p\n", &num);		// 변수 num의 메모리 주소 출력

	return 0;
}