/*
	이미지 필터 적용시 조정
*/

#include <iostream>
using std::cin; using std::cout; using std::endl;

class Point {
public:
	int x, y;	// 좌표값

	Point(int x = 0, int y = 0) : x(x), y(y) {}	// 생성자 (좌표값을 0으로 초기화)

	// 현재 객체의 x, y 값에 num을 각각 더한 새로운 Point 객체 반환
	Point operator+(int num) {
		return Point(this->x + num, this->y + num);
	}

	void print() {		// 좌표값을 출력
		cout << "(" << x << ", " << y << ")\n";
	}
};

int main()
{
	Point pixel(30, 40);	// 초기 픽셀 좌표 설정
	int brightness = 10;	// 밝기 조정값 설정

	pixel = pixel + brightness;		//연산자 오버로딩하여 픽셀 좌표의 밝기 증가 

	cout << "새로운 픽셀 좌표 : ";
	pixel.print();	// (40, 50)

	return 0;
}