#include <stdio.h>

typedef struct score
{
	int kor, eng, math, sum;
	double avg;
} SCORE;


int main()
{
	SCORE s = { 70, 80, 90 };		// 구조체 변수의 초기화(나머지는 0으로 초기화)
	SCORE* p;		// SCORE 타입의 주소를 저장하는 포인터 선언 

	p = &s;

	s.sum = s.kor + s.eng + s.math;
	printf("합계 : %d\n", s.sum);
	
	p->sum = p->kor + p->eng + p->math;
	printf("합계 : %d\n", p->sum);

	(*p).sum = (*p).kor + (*p).eng + (*p).math;
	printf("합계 : %d\n", (*p).sum);

	return 0;
}