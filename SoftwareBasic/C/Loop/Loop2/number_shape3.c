#include <stdio.h>

/*

1000000
0200000
0030000
0004000
0000500
0000060
0000007

*/


int main_t6()
{
	int i, j;

	for (i = 1; i <= 7; i++)
	{
		for (j = 1; j <= 7; j++)
		{
			if (i == j)
				printf("%d", i);
			else 
				printf("%d", 0);
		}
		printf("\n");
	}

	return 0;
}