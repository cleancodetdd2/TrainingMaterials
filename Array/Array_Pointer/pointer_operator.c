#include <stdio.h>

int main_t3()
{
	char c = 'a';
	int i = 3;
	double d = 3.14;

	char* cp = &c;
	int* ip = &i;
	double* dp = &d;

	printf("%p %p %p\n", (void*)cp, (void*)ip, (void*)dp);
	cp++; ip++; dp++;		// 포인터 증가 
	printf("%p %p %p\n", (void*)cp, (void*)ip, (void*)dp);
	return 0;
}