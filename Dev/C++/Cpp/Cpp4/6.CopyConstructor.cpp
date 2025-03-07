#include <iostream>

using std::cout; using std::endl;

class Circle {
private:
	int radius;
public:
	Circle() { this->radius = 1; }
	Circle(int radius) { this->radius = radius; }
	Circle(const Circle& c);			// 복사 생성자 선언
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle(const Circle& c) {		// 복사 생성자 구현 
	this->radius = c.radius;
	cout << "복사 생성자 실행 radius = " << radius << endl;
}


int main()
{
	Circle src(30);		// 객체이름 src, 보통 생성자 호출
	Circle dest(src);	// 객체이름 dest, 복사 생성자 호출 

	cout << "원본의 면적 = " << src.getArea() << endl;
	cout << "복사본의 면적 = " << dest.getArea() << endl;

	return 0;
}