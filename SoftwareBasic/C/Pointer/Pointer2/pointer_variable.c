#include <stdio.h>

int main()
{
	int i = 10;
	char c = 'A';
	double d = 2.1;

	//������ ���� ����
	int* ip;
	char* cp;
	double* dp;

	//������ �ּҰ��� �����Ϳ� ����
	ip = &i;
	cp = &c;
	dp = &d;

	//�Ϲݺ����� ũ��
	printf("i = %zu����Ʈ\n", sizeof(i));
	printf("c = %zu����Ʈ\n", sizeof(c));
	printf("d = %zu����Ʈ\n", sizeof(d));

	//�� �������� ũ��
	printf("\nip = %zu����Ʈ\n", sizeof(ip));
	printf("cp = %zu����Ʈ\n", sizeof(cp));
	printf("dp = %zu����Ʈ\n", sizeof(dp));

	return 0;
}