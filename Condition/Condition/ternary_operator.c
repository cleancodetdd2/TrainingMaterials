#include <stdio.h>

int main_t10()
{
	int num1 = 0;
	int num2;

	//if (num1)
	//	num2 = 100;
	//else
	//	num2 = 200;

	num2 = num1 ? 100 : 200; //num1이 참이면 num2에 100을 할당, 거짓이면 num2에 200 할당	

	printf("%d\n", num2);

	return 0;
}