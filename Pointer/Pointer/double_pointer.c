#include <stdio.h>

int main()
{
	int* numPtr1;			// ���� ������ ����
	int** numPtr2;			// ���� ������ ���� 
	int num = 10;

	numPtr1 = &num;			// num�� �޸� �ּ� ����
	numPtr2 = &numPtr1;		// numPtr1�� �޸� �ּ� ���� 

	printf("%d\n", **numPtr2); // �����͸� �ι� �������Ͽ� num�� �޸� �ּҿ� ����

	int* numPtr3 = 0x1000000;
	printf("%d\n", *numPtr3);

	return 0;
}