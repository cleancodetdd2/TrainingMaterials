#include <stdio.h>

int main_t10()
{
	int num1 = 0;
	int num2;

	//if (num1)
	//	num2 = 100;
	//else
	//	num2 = 200;

	num2 = num1 ? 100 : 200; //num1�� ���̸� num2�� 100�� �Ҵ�, �����̸� num2�� 200 �Ҵ�	

	printf("%d\n", num2);

	return 0;
}