#include <stdio.h>

int main_t8()
{
	int num1 = 2;
	int num2 = 2;
	int num3;
	int num4;

	num3 = num1++;		// num1�� ���� num3�� �Ҵ��� ��,  num1�� �� 1 ����
	num4 = num2--;		// num1�� ���� num4�� �Ҵ��� ��,  num1�� �� 1 ����
	printf("%d %d\n", num3, num4);
	printf("%d %d\n", num1, num2);
	return 0;

}