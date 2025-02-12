#include <iostream>
using std::cin; using std::cout; using std::endl;

class Date;

class Time {
private:
	int hour, min, sec;
public:
	Time(int hour = 0, int min = 0, int sec = 0) : hour(hour), min(min), sec(sec) {}
	friend void todayToString(Date& d, Time& t);
};

class Date {
private:
	int year, month, day;
public:
	Date(int year, int month, int day) : year(year), month(month), day(day) {}
	friend void todayToString(Date& d, Time& t);
};

//전역함수
void todayToString(Date& d, Time& t) {
	cout << "오늘은 " << d.year << "/" << d.month << "/" << d.day << ", "
		<< t.hour << ":" << t.min << ":" << t.sec << endl;
}

int main()
{
	Date d(2025, 2, 12);
	Time t(16, 45, 12);

	todayToString(d, t);

	return 0;
}