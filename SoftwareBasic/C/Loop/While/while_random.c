#include <stdio.h>
#include <stdlib.h>		// rand(), srand()
#include <time.h>		// time()

int main_t4()
{
	srand(time(NULL));

	int i = 0;
	while (i != 3)		// 3�� �ƴ� �� ��� �ݺ� 
	{
		// rand()�Լ� ����Ͽ� ������ ���� �����ѵ� 1~10������ ���ڷ� ����
		i = rand() % 10 + 1;	
		printf("%d\n", i);
	}

	return 0;
}