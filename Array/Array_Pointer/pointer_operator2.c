#include <stdio.h>

int main_t4()
{
	/*
	�迭 �̸� => (�迭�� �����ּҸ��� ����ų�� �ִ�) ������ ���
	������ => ������ ����
	*/
	int* p, a[5] = { 10, 20,30, 40, 50 };

	p = a;

	printf("%p\n", a);
	printf("%d\n", *p);
	printf("%d\n", *(p+1));
	printf("%d\n", p[2]);
	printf("%d\n\n", *(a + 2));

	p = p + 2;
	//a = a + 2;	// �迭 �̸��� ����̱� ������ ���� �Ұ��� 

	p = a + 2;
	//a = p + 2;    // �迭 �̸��� ����̱� ������ ���� �Ұ��� 

	printf("%p\n", a);
	printf("%d\n", *p);
	printf("%d\n", *(p + 2));
	printf("%d\n", *(p - 1));
	printf("%d\n", *p + 2);

	return 0;
}