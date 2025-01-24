/*

1
0 0
111
0000
11111
000000
1111111
00000000
111111111

*/

#include <stdio.h>

int main()
{
	int i, j;

	for (i = 1; i <= 9; i++)			//행
	{
		for (j = 1; j <= i; j++)		//열
		{
			if (i % 2 == 1)				//i가 홀수일 경우
				printf("1 ");
			else						//i가 짝수일 경우
				printf("0 ");
		}
		printf("\n");					//행이 끝날 때 줄바꿈 

	}

	return 0;
}