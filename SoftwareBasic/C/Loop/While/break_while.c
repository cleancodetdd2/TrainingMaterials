#include <stdio.h>

int main()
{
	int num = 0;

	while (1)			//무한 루프
	{
		num++;
		printf("%d\n", num);

		if (num == 100)
			break;		//반복문 끝냄. while 제어흐름을 벗어남 
	}
	return 0;
}