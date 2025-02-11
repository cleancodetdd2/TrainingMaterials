#include <stdio.h>

#define SIZE 2		//�迭 ũ�� ����

//������ ������ �迭�� �޾� ����ϴ� �Լ�
void printIntArray(int* p[])
{
	printf("--------������ ������ �迭----------\n");
	for (int i = 0; i < SIZE; i++)
		printf("������Ʈ %d: %d\n", i, *p[i]);
	printf("\n");
}

//�Ǽ��� ������ �迭�� �޾� ����ϴ� �Լ�
void printDoubleArray(double* p[])
{
	printf("--------�Ǽ��� ������ �迭----------\n");
	for (int i = 0; i < SIZE; i++)
		printf("������Ʈ %d: %.2f\n", i, *p[i]);
	printf("\n");
}

int main()
{
	int x = 8, y = 9;				//���� ����
	double d1 = 3.14, d2 = 5.23;	//�Ǽ� ���� 

	int* pi[SIZE] = { &x, &y };		//������ ������ �迭 �ʱ�ȭ
	double* pd[SIZE] = { &d1, &d2 }; //�Ǽ��� ������ �迭 �ʱ�ȭ 

	//������ �迭�� ���� ������ �� ���
	printf("������ �迭�� ���� ������ �� : \n");
	printf("x: %d, *pi[0]: %d\n", x, *pi[0]);
	printf("y: %d, *pi[1]: %d\n", y, *pi[1]);
	printf("d1: %.2f, *pd[0]: %.2f\n", d1, *pd[0]);
	printf("d2: %.2f, *pd[1]: %.2f\n", d2, *pd[1]);

	printIntArray(pi);
	printDoubleArray(pd);

	return 0;
}