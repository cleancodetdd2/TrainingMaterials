#include <stdio.h>

int main()
{
	int num1 = 5;
	int num2;

	//if (num1)
	//	num2 = 100;
	//else
	//	num2 = 200;

		// ������ �Ǵ��� ����
		// ----	
	num2 = num1 ? 100 : 200;
				//---
				//���϶� ����� ��

	printf("%d\n", num2);

	// �Լ��ȿ��� ���� ������ ���
	printf("%s\n", num1 == 10 ? "10�Դϴ�." : "10�� �ƴմϴ�.");

	return 0;
}