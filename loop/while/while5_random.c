#include <stdio.h>
#include <stdlib.h>		// srand, rand() �Լ��� ����� ���
#include <time.h>		// time �Լ��� ����� ��� 

int main_t5()
{
	srand(time(NULL));  // ���� �ð��� �������� ���� �õ� ���� �ٸ��� ������

	int i = 0;
	while (i != 3) {		// i�� 3�� �ƴ� ���� ��� �ݺ�
		i = rand() % 10;	// �������� ������ ������ �� 10 �̸��� ���ڷ� ����
		printf("%d\n", i);
	}

	return 0;
}
