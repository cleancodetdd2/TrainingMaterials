#include <stdio.h>

int main_t4()
{
	unsigned char num1 = 3;			// 00000011
	unsigned char num2 = 24;		// 00011000

	printf("%u\n", num1 << 3);		// 00011000		���� << �̵��� ��Ʈ ��
	printf("%u\n", num2 >> 2);		// 00000110     ���� >> �̵��� ��Ʈ �� 
	return 0;

}