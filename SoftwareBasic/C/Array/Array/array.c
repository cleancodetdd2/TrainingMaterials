#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a[5];
	int i;	//�迭�� ÷��(�ε���)
	int sum = 0;

	for (i = 0; i < 5; i++)
	{
		printf("%d��° �Է� : ", i + 1);
		if (scanf("%d", &a[i]) != 1) {
			printf("�Է� ���� �Դϴ�.\n");
			return 1;
		}
		//printf("�Է��� �� : a[%d] = %d\n", i, a[i]);
		sum += a[i];		// ������ 
	}

	printf("5������ ����� %.2f�Դϴ�\n", sum / 5.0);

	return 0;
}