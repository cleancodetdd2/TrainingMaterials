#include <stdio.h>

int main_t2()
{
	int i, sum = 0;

	for (i = 1; i <= 10; i++)
	{
		sum += i;
		printf("%d\n", i);
	}
		
	printf("1���� 10������ ���� %d�Դϴ�.\n", sum);

	return 0;
}