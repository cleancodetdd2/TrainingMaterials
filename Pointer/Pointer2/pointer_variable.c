#include <stdio.h>

int main_t2()
{
	char c = 'A';
	int i = 10;
	double d = 2.1;

	//������ ���� ����
	char* cp;
	int* ip;
	double* dp;

	//������ �ּҰ��� �����Ϳ� �ʱ�ȭ
	cp = &c;
	ip = &i;
	dp = &d;

	//�Ϲݺ����� ũ��
	printf("c = %zu����Ʈ\n", sizeof(c));   //%zu�� size_t Ÿ���� ����Ҷ� ����ϴ� ���� ������
	printf("i = %zu����Ʈ\n", sizeof(i));
	printf("d = %zu����Ʈ\n", sizeof(d));

	//�� �������� ũ��
	printf("cp = %zu����Ʈ\n", sizeof(cp));
	printf("ip = %zu����Ʈ\n", sizeof(ip));
	printf("dp = %zu����Ʈ\n", sizeof(dp));

	return 0;
}