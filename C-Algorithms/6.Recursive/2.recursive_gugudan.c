#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ������ 3���� ����Լ��� ����
void printMultiplicatineTable(int num) {
	if (num == 0) {
		printf("��� �Լ� ����\n\n");
		return;
	}

	printMultiplicatineTable(num - 1);	// ���ȣ��(num�� ���ҽ�Ű�鼭 ����)
	printf("3 * %d = %d\n", num, 3 * num);	// ���� ���ڿ� 3�� ���� ��� ���
		
}

int main()
{
	int num;

	printf("����� �ִ� ���� ���� �Է��ϼ��� (��: 7): ");
	if (scanf("%d", &num) != 1) {
		printf("��ȿ�� ���ڸ� �Է��ϼ���.\n");
		return 1;
	}

	if (num < 1) {
		printf("1 �̻��� ���ڸ� �Է��ϼ���.\n");
		return 1;
	}

	printf("3�� ������ ���\n");
	printMultiplicatineTable(num);	//��� �Լ� ȣ�� 

	return 0;
}