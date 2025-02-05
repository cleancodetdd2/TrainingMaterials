#include <iostream>

using std::cout;
using std::endl;
using std::cin;

bool isLeapYear(int year);

int main()
{
	int year;

	cout << "년도 입력 : ";
	cin >> year;

	if (isLeapYear(year))
		cout << year << "년은 윤년 입니다.\n";
	else 
		cout << year << "년은 평년 입니다.\n";
	
	return 0;
}

/*
	윤년
		- 4년마다 한번씩 돌아오는 해
		- 100년마다 돌아오는 해는 평년이 됨
		- 400년마다 돌아오는 해는 윤년이 됨 
*/
bool isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	else if (year % 400 == 0)
		return true;

	return false;	// 평년
}