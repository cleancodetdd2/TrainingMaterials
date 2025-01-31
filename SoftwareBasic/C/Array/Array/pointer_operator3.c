#include <stdio.h>

int main()
{

	int a[] = { 10, 20, 30, 40, 50 };
	int i, j = 10;
	int* ptr;

	ptr = a;	// 포인터 ptr을 배열 a의 첫번째 요소 가리킴
	for (i = 0; i < 5; i++)
		printf("%d ", *ptr++);		//후위 증가 연산자
	printf("\n");

	ptr = a;
	for (i = 0; i < 5; i++)
		printf("%d ", *++ptr);		//전위 증가 연산자 ==>ptr을 먼저 증가시키고, 증가된 위치값 출력
	printf("\n");

	ptr = a;
	for (i = 0; i < 5; i++)
		printf("%d ", ++ * ptr);	//*ptr 값을 먼저 증가시킨 후 출력 
	printf("\n");

	for (i = 0; i < 5; i++, j += 10)
		a[i] = j;

	for (i = 0; i < 5; i++)
		printf("%d ", *ptr++);		//후위 증가 연산자
	printf("\n");

	return 0;
}