#include <stdio.h>

int main()
{
	char c = 'a';
	int i = 3;
	double d = 3.14;

	printf("c = %c\n", c);
	printf("i = %d\n", i);
	printf("d = %.2f\n", d);

	printf("c = %p\n", &c);
	printf("i = %p\n", &i);
	printf("d = %p\n", &d);

	return 0;
}