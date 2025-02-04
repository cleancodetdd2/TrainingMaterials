#include <stdio.h>

typedef struct score
{
	int kor, eng, math, sum;
	double avg;
} SCORE;

int main()
{
	SCORE s[3] = {			// 구조체 배열 초기화
		{70, 70, 70},
		{80, 80, 80},
		{90, 90, 90}
	};

	SCORE* p;		// SCORE 타입의 주소를 저장하는 포인터 선언
	p = s;			// 배열의 이름은 배열의 시작 주소

	s[0].sum = s[0].kor + s[0].eng + s[0].math;
	printf("합계 : %d\n", s[0].sum);

	p[0].sum = p[0].kor + p[0].eng + p[0].math;
	printf("합계 : %d\n", p[0].sum);

	(p + 0)->sum = (p + 0)->kor + (p + 0)->eng + (p + 0)->math;
	printf("합계 : %d\n", (p + 0)->sum);

	(p + 1)->sum = (p + 1)->kor + (p + 1)->eng + (p + 1)->math;
	printf("합계 : %d\n", (p + 1)->sum);

	(*(p + 0)).sum = (*(p + 0)).kor + (*(p + 0)).eng + (*(p + 0)).math;
	printf("합계 : %d\n", (*(p + 0)).sum);

	return 0;
}