#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, i;
	double total = 0.0;

	//�л� �� �Է�
	printf("�л� �� �Է� : ");
	while (scanf("%d", &num) != 1 || num <= 0) {
		printf("�߸��� �Է��Դϴ�. 1 �̻��� ���ڸ� �Է��ϼ���.\n");
		while (getchar() != '\n');	// �Է� ���� ���� 
		printf("�л� �� �Է� : ");
	}

	//���� �޸� �Ҵ�
	double* height = (double*)malloc(sizeof(double) * num);
	if (height == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
		return 1;
	}
	printf("�޸� �Ҵ� ����! (heap area)\n");

	// �л� Ű �Է� (���� �˻�)
	for (i = 0; i < num; i++) {
		do {
			printf("%d��° �л� Ű �Է� (50~250cm) : ", i + 1);
			if (scanf("%lf", &height[i]) != 1) {
				printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
				while (getchar() != '\n');		//�Է� ���� ����
				continue;
			}

			if (height[i] < 50.0 || height[i] > 250.0)
				printf("Ű�� 50cm���� 250cm ���̿��� �մϴ�. �ٽ� �Է��ϼ���\n");

		} while (height[i] < 50.0 || height[i] > 250.0);

		total += height[i];	//Ű �հ�
	}

	// Ű ��� ��� �� ���
	printf("\n%d�� �л��� Ű ����� %.2f cm �Դϴ�.\n", num, total / num);

	//�޸� ����
	free(height);
	height = NULL;
	printf("�޸� ���� �Ϸ�! (heap area)\n");

	return 0;
}