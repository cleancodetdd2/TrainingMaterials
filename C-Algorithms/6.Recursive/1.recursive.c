#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//��� �Լ� : 1 ���� n���� ���
void recursive(int n) {
	if (n == 0)		// ��� ���� ����
		return;

	recursive(n - 1);	// ��� ȣ�� (n-1�� ���ڷ� ����)
	printf("%d\n", n);	// ���� n ���
}

int main()
{
	int num;
	printf("����� ���ڸ� �Է��ϼ���: ");
	if (scanf("%d", &num) != 1) {
		printf("��ȿ�� ���ڸ� �Է��ϼ���.\n");
		return 1;
	}

	if (num < 1) {
		printf("1 �̻��� ���ڸ� �Է��ϼ���.\n");
		return 1;
	}

	printf("1���� %d���� ��� : \n", num);
	recursive(num);		// ��� �Լ�

	return 0;
}
