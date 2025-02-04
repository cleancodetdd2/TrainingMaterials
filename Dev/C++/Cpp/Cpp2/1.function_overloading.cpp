#include <iostream>


//void outDate(int year, int month, int day);
void outDate(int year, int month, int day, char seperate='/');
void outDate(const char* pDate);

int main()
{
	outDate(2025, 2, 4);
	outDate(2026, 3, 10, '\\');
	outDate(2026, 3, 10, '#');
	outDate(2026, 3, 10, ' ');
	outDate("2027년 5월 30일");

	return 0;
}

//void outDate(int year, int month, int day)
//{
//	std::cout << year << '/' << month << '/' << day << std::endl;
//}

void outDate(int year, int month, int day, char seperate)
{
	std::cout << year << seperate << month << seperate << day << std::endl;
}

void outDate(const char* pDate)	//pDate포인터는 문자열 상수의 주소
{
	std::cout << pDate << std::endl;
}