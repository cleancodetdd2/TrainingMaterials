#include <stdio.h>

int main()
{
	void* p;		//� Ÿ���� �ּҶ� ����ų�� �ִ� ������

	int i = 10;
	double d = 3.14;

	p = &i;			// int�� �ּҸ� ����
	//printf("%d\n", *p);	//(�����Ͽ���-������ ������ ��� �Ұ�)
	printf("%d\n", *(int*)p);  //����ȯ �� �������� ���� 

	p = &d;			// double�� �ּҸ� ����
	printf("%.2f\n", *(double*)p);	//����ȯ �� �������� ����

	return 0;
}