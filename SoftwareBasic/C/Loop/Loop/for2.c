#include <stdio.h>

int main_t2()
{
	int i, sum=0;

	for (i = 1; i <= 10; i++)
	{
		printf("%d\n", i);
		sum += i;
	}

	printf("1���� 10������ ���� %d�Դϴ�.\n", sum);

	return 0;
}