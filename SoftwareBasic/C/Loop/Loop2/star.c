/*

*****
****
***
**
*

*/


#include <stdio.h>

int main_t3()
{
	int i, j;
	for(i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 6 - i; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}