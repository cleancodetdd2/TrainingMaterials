#include <stdio.h>

int main_t1()
{
	int i = 1;		//�ʱ��
	// �ݺ��� ����� ���� i�� �����ϰ� 0���� �ʱ�ȭ 
	while (i <= 100)	// �ѹ� �ݺ��Ҷ� ���� i�� 1�� ������Ŵ 
	{				// i�� 100���� ���� �������� �ݺ� 
		printf("Hello World! %d\n", i);
		i++;		//������
	}
	return 0;
}