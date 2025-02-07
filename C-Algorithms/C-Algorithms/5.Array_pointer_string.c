#include <stdio.h>
#include <string.h>

// 문자열 배열을 출력하는 함수
void display(const char* stringArray[], int size)
{
	for (int i = 0; i < size; i++)		//배열 크기만큼 반복
	{
		printf("String: %s\n", stringArray[i]);		//문자열 출력
		int length = strlen(stringArray[i]);		//문자열 길이 계산
		//첫번째 글자 출력
		printf("1st character => %c\n", stringArray[i][0]);
		//세번째 글자 출력(문자열 길이 체크 후 처리)
		printf("3rd character => %c\n", (length > 2) ? stringArray[i][2] : "(N/A)");
		//마지막 글자 출력
		printf("Last character => %c\n\n", stringArray[i][length - 1]);

	}
}

int main()
{
	//문자열 리터럴을 저장하는 배열
	const char* words[] = { "Korea", "China", "Taiwan", "Netherlands", "America" };

	//배열 크기(배열의 원소 개수) -- 전체 배열 크기를 개별 요소 크기로 나눔
	int size = sizeof(words) / sizeof(words[0]);

	//문자열 배열 처리(출력)
	display(words, size);

	return 0;
}