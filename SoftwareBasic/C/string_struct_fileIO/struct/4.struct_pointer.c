#include <stdio.h>

typedef struct score
{
	int kor, eng, math, sum;
	double avg;
} SCORE;


int main()
{
	SCORE s = { 70, 80, 90 };		// ����ü ������ �ʱ�ȭ(�������� 0���� �ʱ�ȭ)
	SCORE* p;		// SCORE Ÿ���� �ּҸ� �����ϴ� ������ ���� 

	p = &s;

	s.sum = s.kor + s.eng + s.math;
	printf("�հ� : %d\n", s.sum);
	
	p->sum = p->kor + p->eng + p->math;
	printf("�հ� : %d\n", p->sum);

	(*p).sum = (*p).kor + (*p).eng + (*p).math;
	printf("�հ� : %d\n", (*p).sum);

	return 0;
}