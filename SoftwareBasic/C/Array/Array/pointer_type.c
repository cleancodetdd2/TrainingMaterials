#include <stdio.h>

int main()
{
	int a[3] = { 1, 2, 3 };		// ������ �迭 a ����
	int* ptr;					// ������ ������ ptr ���� 

	ptr = a;					// �迭���� ù����� �ּҸ� ����

	printf("%d %d %d\n", a[0], a[1], a[2]);		// �迭 a ��ҵ� ���
	printf("%d %d %d\n", ptr[0], ptr[1], ptr[2]);	// ������ ptr�� �̿��Ͽ� �迭 ��ҵ� ���

	return 0;
}