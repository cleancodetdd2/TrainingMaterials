/*

12345
23456
34567
45678
56789

*/

#include <stdio.h>

int main_t4()
{
	int i, j;

	for (i = 1; i <= 5; i++)
	{
		for (j = i; j <= i + 4; j++)
			printf("%d", j);
		printf("\n");
	}

	return 0;
}