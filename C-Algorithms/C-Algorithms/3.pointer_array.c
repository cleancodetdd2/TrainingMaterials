#include <stdio.h>

int main()
{

	int a[4] = { 1, 2, 3, 4 };
	int b[4] = { 5, 6, 7, 8 };
	int* pa[2] = { a, b };		// ������ �迭�� ����Ͽ� �� �迭�� ����Ŵ 

	// (������ ���� Ȱ��) �����
	printf("������ ���� ��� : \n");
	printf("%d\n", *pa[0]);				// a[0]
	printf("%d\n", *(pa[0] + 1));		// a[1]	
	printf("%d\n", *pa[1]);				// b[0]
	printf("%d\n", *(pa[1] + 2));		// b[2]
	printf("%d\n", *pa[1] + 15);		// b[0] + 15 = 20

	printf("\npa[i][j] ��� : \n");
	printf("%d\n", pa[0][0]);			// a[0][0]
	printf("%d\n", pa[0][1]);			// a[0][1]
	printf("%d\n", pa[1][0]);			// b[1][0]
	printf("%d\n", pa[1][2]);			// b[1][2]
	printf("%d\n", pa[1][0] + 15);      // b[1][0] + 15 = 20
	printf("\n");

	printf("�迭 �� ��� (�Ϲ����� ���)\n");
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