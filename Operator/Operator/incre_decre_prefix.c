#include <stdio.h>

int main_t9()
{
	int num1 = 2;
	int num2 = 2;
	int num3;
	int num4;

	num3 = ++num1;		// num1�� �� 1 ������Ų ��, num1�� ���� num3�� �Ҵ�  
	num4 = --num2;		// num2�� �� 1 ���ҽ�Ų ��, num2�� ���� num4�� �Ҵ�
	printf("%d %d\n", num3, num4);		//3, 1
	printf("%d %d\n", num1, num2);		
	return 0;

}