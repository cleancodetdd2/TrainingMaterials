#include <stdio.h>

int main()
{
	int i = 10;
	char c = 'A';
	double d = 2.1;

	// ������ ���� ����� �ʱⰪ �Ҵ� 
	int* ip = &i;
	char* cp = &c;
	double* dp = &d;

	// �����Ϳ� ����� ��
	printf("ip = %p\n", ip);
	printf("cp = %p\n", cp);
	printf("dp = %p\n", dp);

	// �����Ͱ� ����Ű�� �� 
	printf("\nip = %d\n", *ip);
	printf("cp = %d\n", *cp);
	printf("dp = %.2f\n", *dp);

	return 0;
}