/*

56789
45678
34567
23456
12345

*/

#include <stdio.h>

int main_t5()
{
	int i, j;

	for(i = 5; i >= 1; i--)
	{
		for (j = i; j <= i + 4; j++)
			printf("%d", j);
		printf("\n");
	}

	return 0;
}