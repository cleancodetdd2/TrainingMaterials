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

	p = &j;
	printf("\n%d\n", *p);
	printf("%p\n", p);

	*p = *p + 3;
	printf("\n%d\n", i);
	printf("%d\n", j);
	printf("%d\n", *p);

	return 0;
}