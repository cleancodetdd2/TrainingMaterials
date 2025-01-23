#include <stdio.h>

int main_t6()
{
	int i = 0;

	do			// 처음 한번은 아래 코드가 실행됨
	{
		printf("Hello C! %d\n", i);
		i++;
	} while (i < 100);

	return 0;
}