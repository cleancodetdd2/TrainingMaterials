#include <stdio.h>
#include <limits.h>		// ÀÚ·áÇüÀÇ ÃÖ¼Ò°ª, ÃÖ´ñ°ªÀÌ Á¤ÀÇµÈ Çì´õ ÆÄÀÏ 

int main_4()
{
	char num1 = CHAR_MAX;		// charÀÇ ÃÖ´ñ°ª
	short num2 = SHRT_MAX;		// shortÀÇ ÃÖ´ñ°ª
	int num3 = INT_MAX;			// intÀÇ ÃÖ´ñ°ª
	long num4 = LONG_MAX;		// longÀÇ ÃÖ´ñ°ª
	long long num5 = LLONG_MAX; // long longÀÇ ÃÖ´ñ°ª

	printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);
	return 0;
}