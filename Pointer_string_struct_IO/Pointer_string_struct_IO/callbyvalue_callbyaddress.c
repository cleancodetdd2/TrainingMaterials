/*
	Call by Value - ���纻�� �����Ǳ� ������ ���� �������� ������ ��ġ�� ����
*/

#include <stdio.h>

void changeVal(int x, int y);
void changeRef(int* p1, int* p2);

int main()
{
	int a = 3, b = 5;

	changeVal(a, b);	// Call by Value
	printf("changeVal�Լ� ȣ�� �� %d %d\n", a, b);		//���� �ȹٲ�

	changeRef(&a, &b);	// Call by Address
	printf("changeVal�Լ� ȣ�� �� %d %d\n", a, b);		//���� �ٲ� 

	return 0;
}

void changeVal(int x, int y) {		// a,b �� ���纻 x, y 
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void changeRef(int* p1, int* p2)	// a, b�� ����Ű�� �ִ� ������ p1, p2
{
	int temp;
	temp = *p1;			// p1�� ����Ű�� ���� temp�� ����
	*p1 = *p2;			// p2�� ����Ű�� ���� p1�� ����Ű�� ���� ���� 
	*p2 = temp;			// temp�� p2�� ����Ű�� �ִ� ���� ���� 

}