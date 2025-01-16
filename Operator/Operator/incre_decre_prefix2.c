#include <stdio.h>

int main_t11()
{
	int num1 = 2;
	int num2 = 2;

	printf("%d %d\n", ++num1, --num2);	// 증감연산자 먼저 동작한뒤 num1, num2의 값 출력
	printf("%d %d\n", num1, num2);
	return 0;
}