#include <stdio.h>

int main_t3()
{

	long long* numPtr1;			//long long�� ������ ����
	float* numPtr2;				//float�� ������ ���� 
	char* chPtr1;				//char�� ������ ���� 

	long long num1 = 10;
	float num2 = 3.5f;
	char ch1 = 'a';

	numPtr1 = &num1;		//num1�� �޸� �ּ� ���� 
	numPtr2 = &num2;		//num2�� �޸� �ּ� ���� 
	chPtr1 = &ch1;			//ch1�� �޸� �ּ� ���� 

	printf("%lld\n", *numPtr1);
	printf("%f\n", *numPtr2);
	printf("%c\n", *chPtr1);

	return 0;
}