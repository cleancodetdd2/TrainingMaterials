#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void addNumber(int* p1, double* p2, int increase);

int main()
{
	int integer, num;
	double dou;

	//�Է� �ޱ�
	printf("���� �Է� : ");
	if (scanf("%d", &integer) != 1)
	{
		printf("������ �Է��ϼ���\n");
		return 1;
	}

	printf("�Ǽ� �Է� : ");
	if (scanf("%lf", &dou) != 1)
	{
		printf("�Ǽ��� �Է��ϼ���\n");
		return 1;
	}

	printf("���� ���� �Է� : ");
	if (scanf("%d", &num) != 1)
	{
		printf("������ �Է��ϼ���\n");
		return 1;
	}

	addNumber(&integer, &dou, num);
	printf("%d�� ������ ���� : %d, �Ǽ� : %f\n", num, integer, dou);

	return 0;
}

void addNumber(int* p1, double* p2, int increase)
{
	*p1 += increase;
	*p2 += increase;
}