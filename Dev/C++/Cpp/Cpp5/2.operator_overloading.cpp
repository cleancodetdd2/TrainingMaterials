/*
	그래픽 좌표 계산 (2D 게임, CAD 프로그램)
	 - 게임 캐릭터 위치 계산 
*/
#include <iostream>
using std::cin; using std::cout; using std::endl;

//좌표를 멤버변수 갖고 있는 Point 클래스
class Point {
public:
	int x, y;	// 좌표값

	Point(int x = 0, int y = 0) : x(x), y(y) { }	// 생성자 (좌표값을 0으로 초기화)

	Point& operator += (const Point& ref) {		// += 연산자 오버로딩 (좌표 이동 기능)
		this->x += ref.x;		// 현재 객체의 x 좌표에 ref 객체의 x값을 더함 
		this->y += ref.y;		// 현재 객체의 y 좌표에 ref 객체의 y값을 더함 
		return *this;			// 자기 자신을 참조로 변환하여 캐릭터의 연속적인 위치값 연산 가능
	}

	void print() {		// 좌표값을 출력
		cout << "(" << x << ", " << y << ")\n";
	}
};

int main()
{
	Point player(10, 20);		// 플레이어 초기 위치(10, 20)
	Point movePlayer(5, -3);	// 플레이어 이동 벡터(x축 +5, y축 -3)

	player += movePlayer;		// player.operator+=(movePlayer);

	cout << "플레이어 현 위치 : ";
	player.print();				// 플레이어의 새로운 위치

	return 0;
}