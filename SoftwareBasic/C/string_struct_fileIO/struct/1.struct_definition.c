#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NAME_LEN 10
#define GENDER_LEN 5

//구조체 정의 (관련있는 여러개의 변수들의 묶음)
struct student
{
	char name[NAME_LEN];
	int age;
	char gender[GENDER_LEN];
};

int main()
{
	// 구조체 변수 선언(19바이트)
	struct student st, st2;

	// 구조체 변수 초기화 (구조체변수.멤버)
	st.age = 24;
	//st.name = "이순신";	//주소를 대입하라는 의미 

	strcpy(st.name, "이순신");		//문자열 복사 (문자열 리터럴 내용을 배열에 복사)
	strcpy(st.gender, "남자");

	st2.age = 22;
	strcpy(st2.name, "유관순");
	strcpy(st2.gender, "여자");

	printf("\n당신의 이름은 %s이며, 성별은 %s입니다.\n", st.name, st.gender);
	printf("당신의 나이는 %d입니다.\n", st.age);

	printf("\n당신의 이름은 %s이며, 성별은 %s입니다.\n", st2.name, st2.gender);
	printf("당신의 나이는 %d입니다.\n", st2.age);
	return 0;
}