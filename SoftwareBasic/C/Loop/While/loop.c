/*
	while �� : ������ �����ϸ� ���๮ ���� 
	do~while�� : �ϴ� ���๮ ������ ��, ���� ���Ͽ� ������ �����ϸ�
	              ���๮ �ٽ� ����.
*/

#include <stdio.h>

int main_t7()
{
	int i;

	printf("while�� ����\n");
	i = 1;
	while (i <= 100)			//������ ���̸� �ݺ�
	{
		printf("%4d", i++);
		//i++;
	}
	printf("\n");

	printf("do while�� ����\n");
	i = 1;
	do
	{
		printf("%4d", i++);
	} while (i <= 100);
	printf("\n");

	printf("for�� ����\n");
	for(i = 1; i <= 100; i++)
		printf("%4d", i);

	return 0;
}