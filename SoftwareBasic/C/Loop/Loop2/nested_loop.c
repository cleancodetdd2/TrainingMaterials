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
	for (int i = 0; i < 5; i++)		// �ٱ��� ����. ���� ���� 
	{
		for (int j = 0; j < 5; j++)	// ���� ����. ���� ���� 
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