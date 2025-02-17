#include <stdio.h>
#define SQUARE(d) ((d) * (d))

static inline int square(int d) {
	return d * d;
}

#define SUM(a,b) ((a) + (b))
#define MUL(a,b) ((a) * (b))

#define SWAP(type, a, b) \
	do { \
		type temp_swap_var = (a); \
		(a) = (b); \
		(b) = temp_swap_var; \
	} while(0)

int main()
{
	int n = 3, n2 = 5;
	char c = 'a', c2 = 'z';

	if (n == 3)
		SWAP(int, n, n2);		// n�� n2 ���� ��ȯ
	else
		printf("��ȯ�� �� �����ϴ�.\n");

	printf("n = %d, n2 = %d\n", n, n2);		// ��� ���

	SWAP(char, c, c2);
	printf("c = %c, c2 = %c\n", c, c2);		// ��� ���

	printf("%d\n", MUL((1 + 2), (3 + 4)));	// 3 * 7 = 21
	printf("%d\n", SUM(3, 5) * 10);			// (3+5) * 10 = 80
	printf("%.lf\n", (double)SQUARE(n));	// �Ǽ� ���� ���� ->���ۿ�

	n = 3;
	printf("%d\n", SQUARE(n));
	printf("%d\n", SQUARE(++n));	// ���� ������ ���� ���ۿ� �߻� ����
	n = 3;
	printf("%d\n", square(++n));

	return 0;
}