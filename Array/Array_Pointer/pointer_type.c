#include <stdio.h>

int main_t2()
{
	int a[3] = { 1, 2, 3 };
	int* ptr;

	ptr = a;

	printf("%d, %d, %d\n", a[0], a[1], a[2]);
	printf("%d, %d, %d\n", ptr[0], ptr[1], ptr[2]);

	return 0;
}