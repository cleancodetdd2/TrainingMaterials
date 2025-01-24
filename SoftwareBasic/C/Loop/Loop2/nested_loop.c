/*

*
**
***
****
*****


*/
#include <stdio.h>

int main_t1()
{
	for (int i = 0; i < 5; i++)		// 바깥쪽 루프. 세로 방향 
	{
		for (int j = 0; j < 5; j++)	// 안쪽 루프. 가로 방향 
		{
			//printf("j:%d ", j);
			if(j <= i)
				printf("*");
		}
		//printf("i:%d\\n", i);
		printf("\n");
	}

	return 0;
}