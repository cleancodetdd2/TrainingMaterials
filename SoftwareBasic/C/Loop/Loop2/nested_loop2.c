/*

*
  *
    *
      *
        *


*/

#include <stdio.h>

int main_t2()
{
	for (int i = 0; i < 5; i++)		// �ٱ��� ����. ���� ���� 
	{
		for (int j = 0; j < 5; j++)	// ���� ����. ���� ���� 
		{
			if (j == i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}