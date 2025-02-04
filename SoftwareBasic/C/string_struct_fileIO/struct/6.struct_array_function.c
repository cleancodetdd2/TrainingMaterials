#include <stdio.h>

typedef struct score
{
	int kor, eng, math, total;

} score;

void printTotal(score* p);

int main()
{
	score s[3] = {
		{90, 90, 90},
		{100, 100, 100},
		{70, 80, 90}
	};

	printTotal(s);

	return 0;
}

void printTotal(score* p)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		p[i].total = p[i].kor + p[i].eng + p[1].math;
		printf("%d¹ø ÃÑÁ¡ : %d\n", i + 1, p[i].total);
	}
}