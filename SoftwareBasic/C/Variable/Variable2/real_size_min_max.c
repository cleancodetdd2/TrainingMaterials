#include <stdio.h>
#include <float.h>	// �Ǽ� �ڷ����� ��� �ּڰ�, �ִ��� ���ǵ� ��� ����

int main_t5()
{
	float num10 = 0.0f;
	double num20 = 0.0;
	long double num30 = 0.0L;
	printf("float ũ��: %d, double ũ��: %d, long double ũ��: %d\n",
		sizeof(num10), sizeof(num20), sizeof(num30));

	float num1 = FLT_MIN;
	float num2 = FLT_MAX;
	double num3 = DBL_MIN;
	double num4 = DBL_MAX;
	long double num5 = LDBL_MIN;
	long double num6 = LDBL_MAX;
	printf("%.40f %.2f %e %e %Le %Le\n", num1, num2, num3, num4, num5, num6);

	return 0;
}