#include <stdio.h>

int main_t8()
{
	int num = 0;

	while (1)			//���� ����
	{
		num++;
		printf("%d\n", num);

		if (num == 100)
			break;		//�ݺ��� ����. while �����帧�� ��� 
	}
	return 0;
}