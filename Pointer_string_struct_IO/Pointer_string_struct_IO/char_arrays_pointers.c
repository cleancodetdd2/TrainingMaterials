#include <stdio.h>

int main()
{
	char str[] = "apple";	//�迭�� �̿��Ͽ� ���ڿ� ó��
	char* sp = "straberry";	//�����͸� �̿��Ͽ� ���ڿ� ó�� 
	int i;

	printf("%s\n", str);
	printf("%s\n", sp);

	for (i = 0; str[i] != '\0'; i++)		//�ι��� ��������
		str[i] -= 32;		//�빮�ڷ� ��ȯ => �迭�� ���� ���� 

	printf("\n%s\n", str);

	for (i = 0; sp[i] != '\0'; i++)
		sp[i] -= 32;		//�빮�ڷ� ��ȯ�ȵ� => �����ʹ� ���� �Ұ���

	printf("%s\n", sp);

	return 0;
}
