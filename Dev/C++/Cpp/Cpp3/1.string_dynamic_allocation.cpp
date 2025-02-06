#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using std::cout; using std::endl; using std::cin;

// 두개의 char* 포인터를 교환하는 함수 선언
void swap(char*& ptr1, char*& ptr2);

int main()
{
	char* str1 = new char[20];	// 길이가 20인 문자 배열을 동적으로 할당
	char* str2 = new char[10];  // 길이가 10인 문자 배열을 동적으로 할당

	strcpy(str1, "Happy New Year!");	//str1에 "Happy New Year!" 문자열 복사함
	strcpy(str2, "megait");

	cout << "original : " << str1 << ", " << str2 << endl;
	swap(str1, str2);		// str1과 str2의 포인터 값을 교환 
	cout << "after swap() : " << str1 << ", " << str2 << endl;
	// 동적으로 할당된 메모리 해제
	delete[] str1;
	delete[] str2;

	return 0;
}

void swap(char*& ptr1, char*& ptr2)
{
	char* temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}