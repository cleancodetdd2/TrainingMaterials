#include <stdio.h>

typedef struct score
{
	int kor, eng, math, sum;
	double ave;
} SCORE;

int main()
{
	SCORE s[3] = {
		{70, 70, 70},
		{80, 80, 80},
		{90, 90, 90}
	};	// ����ü �迭�� �ʱ�ȭ (���������� �ʱ�ȭ ��, �������� 0���� ä��)

	SCORE* p;	//SCOREŸ���� �ּҸ� �����ϴ� ������ ���� 
	p = s;		//�迭�� �迭�� ���� �ּ� 

	s[0].sum = s[0].kor + s[0].eng + s[0].math;
	printf("�հ� : %d\n", s[0].sum);

	p[0].sum = p[0].kor + p[0].eng + p[0].math;
	printf("�հ�2 : %d\n", p[0].sum);

	(p + 0)->sum = (p + 0)->kor + (p + 0)->eng + (p + 0)->math;
	printf("�հ�3 : %d\n", (p + 0)->sum);

	(*(p + 0)).sum = (*(p + 0)).kor + (*(p + 0)).eng + (*(p + 0)).math;
	printf("�հ�4 : %d\n", (*(p + 0)).sum);

	return 0;
}