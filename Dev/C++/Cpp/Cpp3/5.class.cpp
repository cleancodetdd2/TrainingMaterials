#include <iostream>
using std::cin; using std::cout; using std::endl;

class Circle {
public:
	//멤버변수
	double mRadius = 0;
	const double PI = 3.141592;

	//멤버함수
	void SetRadius(double radius) {
		mRadius = radius;
	}

	double GetArea() {
		return PI * mRadius * mRadius;
	}

	double GetCircumference() {
		return 2 * PI * mRadius;
	}

};

int main()
{
	//클래스 변수 선언
	Circle cir;		//클래스 변수 선언
	cir.SetRadius(10.2);

	cout << "원의 둘레는" << cir.GetCircumference() << endl;

	return 0;
}