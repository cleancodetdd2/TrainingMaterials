#include <iostream>
using std::cin; using std::cout; using std::endl;

/*
	* Coding Convension
	1. 클래스명은 파스칼 표기법을 따름
		- ex) OrderList, NewCar
	2. 클래스의 멤버변수명 앞에는 접두어 m을 붙인 후, 카멜 표기법으로 씀
		- ex) mName, mAge
	3. 함수의 매개변수나 지역변수는 케멜 표기법을 씀
		- ex) height, width 
	4. public 멤버 함수는 파스칼 표기법을 씀
		- ex) SetName, GetName
*/
class Triangle {
public:
	//멤버변수
	double mBase = 0, mHeight = 0;

	//멤버함수 
	void SetTriangle(double base, double height) {
		mBase = base;
		mHeight = height;
	}

	double getArea() {
		return mBase * mHeight / 2;
	}
};

int main() {
	Triangle tri;	// 클래스 변수 
	tri.SetTriangle(30, 50);
	cout << "삼각형의 넓이는 " << tri.getArea() << "입니다.\n";

	return 0;
}