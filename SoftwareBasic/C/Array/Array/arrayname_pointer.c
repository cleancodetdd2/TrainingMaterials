#include <stdio.h>

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };

	printf("%d %d\n", a[0], a[1]);
	printf("%p %p\n", (void*)&a[0], (void*)&a[1]);
	printf("%p\n", (void*)a);

	return 0;
}