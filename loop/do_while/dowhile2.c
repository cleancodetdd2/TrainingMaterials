#include <stdio.h>

int main_t2()
{
	int i = 100;

	do		// 100부터 1까지 감소하면서 100번 반복
	{
		printf("Hello World!    %d \n", i);
		i--;
	} while (i > 0);
	return 0;
}