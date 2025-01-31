/*
	void*
		- ���� ������
		- ������ Ÿ��(char*, int*, double*)�� �پ��ϰ� �����ϴµ�
		  ISO C���� ������ ����� �� %p�� void* Ÿ���� �����͸� ������.
			- ��� �Ǵ� ������ ���ǵ��� ���� �� �� ����.
	
*/
#include <stdio.h>

int main()
{
	char c = 'a';
	int i = 3;
	double d = 3.14;

	char* cp = &c;
	int* ip = &i;
	double* dp = &d;

	printf("%p %p %p\n", (void*)cp, (void*)ip, (void*)dp);
	cp++; ip++; dp++;
	printf("%p %p %p\n", (void*)cp, (void*)ip, (void*)dp);

	return 0;
}