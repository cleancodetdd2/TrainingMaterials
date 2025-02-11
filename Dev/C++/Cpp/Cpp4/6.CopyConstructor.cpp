#include <iostream>

using std::cout; using std::endl;

class Circle {
private:
	int radius;
public:
	Circle() { this->radius = 1; }
	Circle(int radius) { this->radius = radius; }
	Circle(const Circle& c);			// ���� ������ ����
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle(const Circle& c) {		// ���� ������ ���� 
	this->radius = c.radius;
	cout << "���� ������ ���� radius = " << radius << endl;
}


int main()
{
	Circle src(30);		// ��ü�̸� src, ���� ������ ȣ��
	Circle dest(src);	// ��ü�̸� dest, ���� ������ ȣ�� 

	cout << "������ ���� = " << src.getArea() << endl;
	cout << "���纻�� ���� = " << dest.getArea() << endl;

	return 0;
}