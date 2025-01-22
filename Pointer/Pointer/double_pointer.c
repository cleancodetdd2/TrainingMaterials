#include <stdio.h>

int main()
{
	int* numPtr1;			// 단일 포인터 선언
	int** numPtr2;			// 이중 포인터 선언 
	int num = 10;

	numPtr1 = &num;			// num의 메모리 주소 저장
	numPtr2 = &numPtr1;		// numPtr1의 메모리 주소 저장 

	printf("%d\n", **numPtr2); // 포인터를 두번 역참조하여 num의 메모리 주소에 접근

	int* numPtr3 = 0x1000000;
	printf("%d\n", *numPtr3);

	return 0;
}