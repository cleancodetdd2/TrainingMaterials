#include <stdio.h>

int main()
{
	int* p;
	int i = 3, j;

	p = &i;
	j = *p;
	j++;

	printf("%d\n", *p);
	printf("%p\n", p);
	printf("%d\n", j);

	printf("\n");

	p = &j;
	printf("%d\n", *p);
	printf("%p\n", p);
	
	printf("\n");

	*p = *p + 3;
	printf("%d\n", i);
	printf("%d\n", j);
	printf("%d\n", *p);

	return 0;
}