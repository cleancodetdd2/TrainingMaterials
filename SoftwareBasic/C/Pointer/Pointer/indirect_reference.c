#include <stdio.h>

int main()
{
	int* numPtr;		// ������ ���� ����
	int num = 10;		// ������ ���� �����ϰ� 10���� �ʱ�ȭ(����)

	numPtr = &num;		// num�� �޸� �ּҸ� ������ ������ ���� 

	printf("%d\n", *numPtr);	// ������ ������, num�� �޸� �ּҿ� �����Ͽ� ���� ������

	*numPtr = 20;		// ������ �����ڷ� �޸� �ּҿ� �����Ͽ� 20�� ���� 
	printf("%d\n", *numPtr);
	printf("%d\n", num);		// ���� num�� ���� �ٲ� 

	return 0;
}