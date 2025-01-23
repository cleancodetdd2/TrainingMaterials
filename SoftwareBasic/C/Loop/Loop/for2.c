#include <stdio.h>

int main_t2()
{
	int i, sum=0;

	for (i = 1; i <= 10; i++)
	{
		printf("%d\n", i);
		sum += i;
	}

	printf("1부터 10까지의 합은 %d입니다.\n", sum);

	return 0;
}