#include <stdio.h>

int main_t2()
{
	unsigned char num1 = 1;				// 0000 0001
	unsigned char num2 = 3;				// 0000 0011

	printf("%d\n", num1 & num2);		// 01�� 11�� ��Ʈ AND => 01
	printf("%d\n", num1 | num2);		// 01�� 11�� ��Ʈ OR => 11
	printf("%d\n", num1 ^ num2);		// 01�� 11�� ��Ʈ XOR => 10
	return 0;
}