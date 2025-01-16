#include <stdio.h>

int main_t8()
{
	int num1 = 2;
	int num2 = 2;
	int num3;
	int num4;

	num3 = num1++;		// num1의 값을 num3에 할당한 뒤,  num1의 값 1 증가
	num4 = num2--;		// num1의 값을 num4에 할당한 뒤,  num1의 값 1 감소
	printf("%d %d\n", num3, num4);
	printf("%d %d\n", num1, num2);
	return 0;

}