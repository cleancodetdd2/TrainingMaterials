#include <stdio.h>

int main(void)
{
	printf("%zu\n", sizeof(int));
	printf("%zu\n", sizeof(long long));
	printf("%zu\n", sizeof(1));
	printf("%zu\n", sizeof(2.4));
	return 0;
}