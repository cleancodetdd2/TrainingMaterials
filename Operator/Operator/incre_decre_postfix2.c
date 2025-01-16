#include <stdio.h>

int main_t10()
{
	int num1 = 2;
	int num2 = 2;

	printf("%d %d\n", num1++, num2--);	// num1, num2의 값을 먼저 출력한 뒤 증감연산자 동작
	printf("%d %d\n", num1, num2);
	return 0;
}