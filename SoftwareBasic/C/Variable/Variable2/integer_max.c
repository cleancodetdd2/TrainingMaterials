#include <stdio.h>
#include <limits.h>		// �ڷ����� �ּҰ�, �ִ��� ���ǵ� ��� ���� 

int main_4()
{
	char num1 = CHAR_MAX;		// char�� �ִ�
	short num2 = SHRT_MAX;		// short�� �ִ�
	int num3 = INT_MAX;			// int�� �ִ�
	long num4 = LONG_MAX;		// long�� �ִ�
	long long num5 = LLONG_MAX; // long long�� �ִ�

	printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);
	return 0;
}