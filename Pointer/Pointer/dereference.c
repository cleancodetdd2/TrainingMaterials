#include <stdio.h>

int main_t2()
{
	int* numPtr;			// 포인터 변수 선언 (자료형* 포인터이름)
	int num = 10;

	numPtr = &num;			// num의 메모리 주소를 포인터 변수에 저장
	printf("origin %d\n", *numPtr);  //역참조 연산자, num의 메모리 주소에 접근하여 값을 가져옴

	*numPtr = 20;		// 역참조 연산자로 메모리 주소에 접근하여 20을 저장 

	printf("derefer %d\n", *numPtr);
	printf("%d\n", num);		// 실제 num의 값도 바뀜 

	return 0;
}