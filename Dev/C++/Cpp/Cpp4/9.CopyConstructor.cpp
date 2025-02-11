#include <iostream>

using std::cin; using std::cout; using std::endl;

class Point {
private:
	int mX, mY;
public:
	Point() : mX(0), mY(0) {
		cout << "1.持失切\n";
	}
	
	Point(int x, int y) : mX(x), mY(y) {
		cout << "2.持失切\n";
	}

	Point(const Point& ref) {
		this->mX = ref.mX;
		this->mY = ref.mY;
		cout << "3.差紫 持失切\n";
	}

	int GetX() const {
		return this->mX;
	}

	int GetY() const {
		return this->mY;
	}
};

int main()
{
	Point p1;
	Point p2(2, 3);
	//Point p3 = p2;
	Point p3(p2);

	cout << "p1(" << p1.GetX() << ", " << p1.GetY() << ")\n";
	cout << "p2(" << p2.GetX() << ", " << p2.GetY() << ")\n";
	cout << "p3(" << p3.GetX() << ", " << p3.GetY() << ")\n";

	return 0;
}