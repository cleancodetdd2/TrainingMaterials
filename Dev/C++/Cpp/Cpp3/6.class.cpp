#include <iostream>
using std::cin; using std::cout; using std::endl;

class Trapezoid {
public:
	//멤버변수
	double mTop = 0, mBase = 0, mHeight = 0;

	//멤버함수
	void SetTrapezoid(double top, double base, double height);
	double GetArea();
};

//:: 연산자 ==> 범위 지정 연산자 

void Trapezoid::SetTrapezoid(double top, double base, double height) {
	mTop = top;
	mBase = base;
	mHeight = height;
}

double Trapezoid::GetArea() {
	return (mTop + mBase) * mHeight / 2;
}

int main()
{
	double top, base, height;
	cout << "윗변, 밑변, 높이를 입력하시오(공백 구분) : ";
	cin >> top >> base >> height;

	Trapezoid trap;		// 클래스 변수 선언 
	trap.SetTrapezoid(top, base, height);

	cout << "사다리꼴 넓이는 " << trap.GetArea() << "입니다.\n";

	return 0;
}