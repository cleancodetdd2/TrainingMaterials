#include <stdio.h>

int main_t2()
{
	int i = 100;

	do		// 100���� 1���� �����ϸ鼭 100�� �ݺ�
	{
		printf("Hello World!    %d \n", i);
		i--;
	} while (i > 0);
	return 0;
}