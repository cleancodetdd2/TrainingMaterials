#include <stdio.h>

int main_t2()
{
	int* numPtr;			// ������ ���� ����
	int num = 10;			// int�� ���� �����ϰ� �ʱ�ȭ

	numPtr = &num;			// num�� �޸� �ּҸ� ������ ������ ����

	printf("%p\n", numPtr);		// ������ ���� numPtr�� �� ���

	printf("%p\n", &num);		// ���� num�� �޸� �ּ� ���

	return 0;
}