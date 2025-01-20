#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	if (scanf("%d", &n) != 1) {
		printf("입력 오류\n");
		return 1;
	}
	printf("n = %d\n", n);
	return 0;
}