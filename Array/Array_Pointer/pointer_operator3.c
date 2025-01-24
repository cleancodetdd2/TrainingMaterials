#include <stdio.h>

int main()
{
	int a[] = { 10, 20, 30, 40, 50 };
	int i, j = 10;
	int* ptr;

	ptr = a;
	for (i = 0; i < 5; i++)
		printf("%d ", *ptr++);	//*ptr와 ptr++이 결합된 형태
	printf("\n");

	ptr = a;
	for (i = 0; i < 5; i++)
		printf("%d ", *++ptr);   //++ptr와 *ptr이 결합된 형태
	printf("\n");

	ptr = a;
	for (i = 0; i < 5; i++)
		printf("%d ", ++ * ptr);   // ++a[i]와 같은 형태
	printf("\n");

	ptr = a;
	for (i = 0; i < 5; i++, j += 10)
		a[i] = j;				   // 10 20 30 40 50 
	
	ptr = a;
	for (i = 0; i < 5; i++)
		printf("%d ", (*ptr)++);	// a[i]++  10 11 12 13 14
	printf("\n");

	return 0;
}