#include <stdio.h>

typedef struct score
{
	int kor, eng, math, sum;
	double avg;
} SCORE;

int main()
{
	SCORE s[3] = {			// ����ü �迭 �ʱ�ȭ
		{70, 70, 70},
		{80, 80, 80},
		{90, 90, 90}
	};

	SCORE* p;		// SCORE Ÿ���� �ּҸ� �����ϴ� ������ ����
	p = s;			// �迭�� �̸��� �迭�� ���� �ּ�

	s[0].sum = s[0].kor + s[0].eng + s[0].math;
	printf("�հ� : %d\n", s[0].sum);

	p[0].sum = p[0].kor + p[0].eng + p[0].math;
	printf("�հ� : %d\n", p[0].sum);

	(p + 0)->sum = (p + 0)->kor + (p + 0)->eng + (p + 0)->math;
	printf("�հ� : %d\n", (p + 0)->sum);

	(p + 1)->sum = (p + 1)->kor + (p + 1)->eng + (p + 1)->math;
	printf("�հ� : %d\n", (p + 1)->sum);

	(*(p + 0)).sum = (*(p + 0)).kor + (*(p + 0)).eng + (*(p + 0)).math;
	printf("�հ� : %d\n", (*(p + 0)).sum);

	return 0;
}