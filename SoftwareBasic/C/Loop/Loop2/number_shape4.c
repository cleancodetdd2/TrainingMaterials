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

	for (i = 1; i <= 9; i++)			//��
	{
		for (j = 1; j <= i; j++)		//��
		{
			if (i % 2 == 1)				//i�� Ȧ���� ���
				printf("1 ");
			else						//i�� ¦���� ���
				printf("0 ");
		}
		printf("\n");					//���� ���� �� �ٹٲ� 

	}

	return 0;
}