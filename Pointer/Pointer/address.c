#include <stdio.h>

int main_t1()
{
	int* numPtr;			// ������ ���� ���� (�ڷ���* �������̸�)
	int num = 10;

	numPtr = &num;

	printf("%p\n", numPtr); // ������ ���� numPtr�� �� ��� 
	printf("%p\n", &num);	// num�� �޸� �ּҸ� ���(��ǻ�͸���, ������ ������ �޶���)

	return 0;
}