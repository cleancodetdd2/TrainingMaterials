#include <stdio.h>

int main_t3()
{
	const int con1 = 1;				// ���. ����� ���ÿ� �ʱ�ȭ 
	const float con2 = 0.1f;
	const char con3 = 'a';

	//con1 = 2;			// ����� ���� �Ҵ��ϸ� ������ ���� �߻� 
	printf("%d %f %c\n", con1, con2, con3);
	return 0;
}