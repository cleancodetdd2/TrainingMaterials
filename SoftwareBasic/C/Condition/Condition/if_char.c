#include <stdio.h>

int main_t2()
{
	float num = 0.1f;
	char ch = 'a';

	if (num == 0.1f)		// �Ǽ� ��
		printf("0.1�Դϴ�.\n");

	if(ch == 'a')			// ���� ��
		printf("a�Դϴ�.\n");

	if(ch == 97)			// ���ڸ� ASCII �ڵ�� ��
		printf("a�Դϴ�...\n");

	return 0;
}