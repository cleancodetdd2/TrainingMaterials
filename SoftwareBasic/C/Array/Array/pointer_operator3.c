#include <stdio.h>

int main()
{

	int a[] = { 10, 20, 30, 40, 50 };
	int i, j = 10;
	int* ptr;

	ptr = a;	// ������ ptr�� �迭 a�� ù��° ��� ����Ŵ
	for (i = 0; i < 5; i++)
		printf("%d ", *ptr++);		//���� ���� ������
	printf("\n");

	ptr = a;
	for (i = 0; i < 5; i++)
		printf("%d ", *++ptr);		//���� ���� ������ ==>ptr�� ���� ������Ű��, ������ ��ġ�� ���
	printf("\n");

	ptr = a;
	for (i = 0; i < 5; i++)
		printf("%d ", ++ * ptr);	//*ptr ���� ���� ������Ų �� ��� 
	printf("\n");

	for (i = 0; i < 5; i++, j += 10)
		a[i] = j;

	for (i = 0; i < 5; i++)
		printf("%d ", *ptr++);		//���� ���� ������
	printf("\n");

	return 0;
}