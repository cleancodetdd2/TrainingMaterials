#include <stdio.h>

int main()
{
	int a[3] = { 1, 2, 3 };		// 정수형 배열 a 선언
	int* ptr;					// 정수형 포인터 ptr 선언 

	ptr = a;					// 배열명은 첫요소의 주소를 가짐

	printf("%d %d %d\n", a[0], a[1], a[2]);		// 배열 a 요소들 출력
	printf("%d %d %d\n", ptr[0], ptr[1], ptr[2]);	// 포인터 ptr를 이용하여 배열 요소들 출력

	return 0;
}