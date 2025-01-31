#include <stdio.h>

//�Լ� ����
void changeVal(int x, int y);
void changeRef(int* p1, int* p2);

int main()
{
	int a = 3, b = 5;
	changeVal(a, b);
	printf("changeVal() �Լ� ȣ�� �� %d %d\n", a, b);

	changeRef(&a, &b);
	printf("changeRef() �Լ� ȣ�� �� %d %d\n", a, b);
	return 0;
}

// �Ű����� x, y�� ���纻�� ���� (���� ����)
void changeVal(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
} // �Լ��� ����Ǹ� x�� y�� �Ҹ��

// �Ű������� �����͸� ���� ���� ������ ���� ����
void changeRef(int* p1, int* p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}