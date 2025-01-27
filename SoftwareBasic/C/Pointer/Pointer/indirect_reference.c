#include <stdio.h>

int main()
{
	int* numPtr;		// 포인터 변수 선언
	int num = 10;		// 정수형 변수 선언하고 10으로 초기화(저장)

	numPtr = &num;		// num의 메모리 주소를 포인터 변수에 저장 

	printf("%d\n", *numPtr);	// 역참조 연산자, num의 메모리 주소에 접근하여 값을 가져옴

	*numPtr = 20;		// 역참조 연산자로 메모리 주소에 접근하여 20을 저장 
	printf("%d\n", *numPtr);
	printf("%d\n", num);		// 실제 num의 값도 바뀜 

	return 0;
}