#include <stdio.h>

int main_t1()
{
	char c = 'a';
	int i = 3;
	double d = 3.14;

	printf("c = %d\n", c);
	printf("i = %d\n", i);
	printf("d = %.2f\n", d);

	printf("c = %p\n", &c);
	printf("i = %p\n", &i);
	printf("d = %p\n", &d);

	return 0;
}