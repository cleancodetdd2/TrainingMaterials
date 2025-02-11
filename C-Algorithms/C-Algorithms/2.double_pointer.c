#include <stdio.h>

void updateValue(int** ptr)
{
	static int temp = 42;		//���� ����
	*ptr = &temp;				//���������͸� �̿��Ͽ� �� ���� 
}

int main()
{
	int i = 3;
	int* p, ** pp;

	p = &i;
	pp = &p;

	printf("�ּ� �� Ȯ�� : \n");
	printf("i = %d, *p = %d, **pp = %d\n", i, *p, **pp);
	printf("&i = %p, p = %p, *pp = %p\n", (void*)&i, (void*)p, (void*)*pp);
	printf("&p = %p, pp =%p\n", (void*)&p, (void*)pp);

	//���� �����͸� �̿��ؼ� �� ����
	updateValue(&p);
	printf("\n\nupdateValue()ȣ�� �� �ּ� �� Ȯ�� :\n");
	printf("*p = %d, **pp = %d\n", *p, **pp);
	printf("p = %p, *pp = %p\n", (void*)p, (void*)*pp);

	return 0;
}