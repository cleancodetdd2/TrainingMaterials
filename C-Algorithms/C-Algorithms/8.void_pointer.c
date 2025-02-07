#include <stdio.h>

// void* �����͸� Ȱ���� ���� ��� �Լ�
void print_value(void* p, char type)
{
	switch (type) {
	case 'i':
		printf("���� : %d\n", *(int*)p);
		break;
	case 'd':
		printf("�Ǽ� : %.2f\n", *(double*)p);
		break;
	case 'c':
		printf("���� : %c\n", *(char*)p);
		break;
	default:
		printf("�������� �ʴ� Ÿ���Դϴ�.\n");
	}

}

int main()
{
	void* p;		//���� ������ ����

	int i = 42;
	double d = 3.14159;
	char c = 'A';

	p = &i;
	print_value(p, 'i');

	p = &d;
	print_value(p, 'd');

	p = &c;
	print_value(p, 'c');

	// void*�� Ȱ���Ͽ� �迭ó��
	int numbers[] = { 10, 20, 30, 40, 50 };
	p = numbers;		//�迭�� ù��° �ּ� ���� 
	for (int j = 0; j < 5; j++)
		printf("numbers[%d]: %d\n", j, *((int*)p + j));

	return 0;
}