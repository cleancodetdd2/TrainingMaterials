#include <stdio.h>

int main()
{

	int a[4] = { 1, 2, 3, 4 };
	int b[4] = { 5, 6, 7, 8 };
	int* pa[2] = { a, b };		// 포인터 배열을 사용하여 두 배열을 가리킴 

	// (포인터 연산 활용) 값출력
	printf("포인터 연산 방식 : \n");
	printf("%d\n", *pa[0]);				// a[0]
	printf("%d\n", *(pa[0] + 1));		// a[1]	
	printf("%d\n", *pa[1]);				// b[0]
	printf("%d\n", *(pa[1] + 2));		// b[2]
	printf("%d\n", *pa[1] + 15);		// b[0] + 15 = 20

	printf("\npa[i][j] 방식 : \n");
	printf("%d\n", pa[0][0]);			// a[0][0]
	printf("%d\n", pa[0][1]);			// a[0][1]
	printf("%d\n", pa[1][0]);			// b[1][0]
	printf("%d\n", pa[1][2]);			// b[1][2]
	printf("%d\n", pa[1][0] + 15);      // b[1][0] + 15 = 20
	printf("\n");

	printf("배열 값 출력 (일반적인 방식)\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d", pa[i][j]);		
		}
		printf("\n");
	}

	return 0;
}