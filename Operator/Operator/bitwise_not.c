#include <stdio.h>

int main_t3()
{
	unsigned char num1 = 162;			// 1010 0010
	unsigned char num2;

	num2 = ~num1;						// 0101 1101
	printf("%u\n", num2);

	return 0;
}