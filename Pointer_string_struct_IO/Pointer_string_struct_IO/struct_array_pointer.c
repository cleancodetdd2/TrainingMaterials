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
	};	// 구조체 배열의 초기화 (변수단위로 초기화 후, 나머지는 0으로 채움)

	SCORE* p;	//SCORE타입의 주소를 저장하는 포인터 선언 
	p = s;		//배열은 배열의 시작 주소 

	s[0].sum = s[0].kor + s[0].eng + s[0].math;
	printf("합계 : %d\n", s[0].sum);

	p[0].sum = p[0].kor + p[0].eng + p[0].math;
	printf("합계2 : %d\n", p[0].sum);

	(p + 0)->sum = (p + 0)->kor + (p + 0)->eng + (p + 0)->math;
	printf("합계3 : %d\n", (p + 0)->sum);

	(*(p + 0)).sum = (*(p + 0)).kor + (*(p + 0)).eng + (*(p + 0)).math;
	printf("합계4 : %d\n", (*(p + 0)).sum);

	return 0;
}