#include <stdio.h>

int main_t2()
{
	int* numPtr;			// ������ ���� ���� (�ڷ���* �������̸�)
	int num = 10;

	numPtr = &num;			// num�� �޸� �ּҸ� ������ ������ ����
	printf("origin %d\n", *numPtr);  //������ ������, num�� �޸� �ּҿ� �����Ͽ� ���� ������

	*numPtr = 20;		// ������ �����ڷ� �޸� �ּҿ� �����Ͽ� 20�� ���� 

	printf("derefer %d\n", *numPtr);
	printf("%d\n", num);		// ���� num�� ���� �ٲ� 

	return 0;
}