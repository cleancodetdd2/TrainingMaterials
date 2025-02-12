#include <iostream>
using std::cin; using std::cout; using std::endl;

class Date;

class Time {
private:
	int hour, min, sec;
public:
	Time(int hour = 0, int min = 0, int sec = 0) : hour(hour), min(min), sec(sec) {}
	friend class Date;		// 클래스를 friend로 선언 
};

class Date {
private:
	int year, month, day;
public:
	Date(int year, int month, int day) : year(year), month(month), day(day) {}
	void todayToString(Time& t) {
		cout << "오늘은 " << this->year << "/" << this->month << "/" << this->day << ", "
			<< t.hour << ":" << t.min << ":" << t.sec << endl;
	}
};

int main()
{

	Date d(2025, 2, 12);
	Time t(16, 45, 12);

	d.todayToString(t);

	return 0;
}