/*
 
*
**
***
****
*****

*/
#include <stdio.h>

int main_t3()
{
	for (int i = 0; i < 5; i++)			// �ٱ��� ����(���� ����)
	{
		for (int j = 0; j < 5; j++)		// ���� ����(���� ����)
		{
			if(j <= i)
				printf("*");
		}
		printf("\n");
	}

	return 0;
}