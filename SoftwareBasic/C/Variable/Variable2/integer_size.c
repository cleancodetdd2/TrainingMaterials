/*�ڷ��� ũ�� Ȯ��
	- sizeof, sizeof()
*/
#include <stdio.h>

int main_t2()
{
	int num1 = 0;
	int size = sizeof num1;	

	printf("num1�� ũ�� : %d\n", size);
	printf("char: %d, short: %d, int: %d, long: %d, long long: %d\n",
		sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(long long));

	return 0;
}