#include <stdio.h>

int main_t2(void) {
	int add = 3 + 7;			// ���� ���ͷ�
	printf("3 + 7 = %d\n", add);	// ���ڿ� ���ͷ� 
	printf("%d X %d = %d\n", 30, 100, 30 * 100);
	printf("%f\n", 0.1F);		// �Ǽ� ���ͷ� �Ҽ��� ǥ��� 0.100000
	printf("%f\n", 1.0E-5f);	// �Ǽ� ���ͷ� ���� ǥ���  0.000010 
	printf("%c\n", 'a');		// ���� ���ͷ� 
	return 0;
}