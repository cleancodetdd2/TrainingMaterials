#include <stdio.h>

int main_t3()
{
	float num1 = 0.1f;
	char c1 = 'a';

	if (num1 == 0.1f)		//�Ǽ� ��
		printf("0.1�Դϴ�.\n");

	if(c1 == 'a')			//���� �� 
		printf("a�Դϴ�.\n");

	if(c1 == 97)			//���ڸ� ASCII �ڵ�� �� 
		printf("a�Դϴ�2.\n");

	return 0;
}