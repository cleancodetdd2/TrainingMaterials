#include <stdio.h>

int main_t1()
{
	char ch = 'a';
	int n = 1;
	double d = 1.0;

	printf("ch�� �ּ� : %p\n", &ch);   // &(�ּ� ������)�� ������ �޸� �ּ� ���
	printf("n�� �ּ� : %p\n", &n);
	printf("d�� �ּ� : %p\n", &d);

	return 0;
}