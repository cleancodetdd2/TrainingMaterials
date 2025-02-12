/*
	�̹��� ���� ����� ����
*/

#include <iostream>
using std::cin; using std::cout; using std::endl;

class Point {
public:
	int x, y;	// ��ǥ��

	Point(int x = 0, int y = 0) : x(x), y(y) {}	// ������ (��ǥ���� 0���� �ʱ�ȭ)

	// ���� ��ü�� x, y ���� num�� ���� ���� ���ο� Point ��ü ��ȯ
	Point operator+(int num) {
		return Point(this->x + num, this->y + num);
	}

	void print() {		// ��ǥ���� ���
		cout << "(" << x << ", " << y << ")\n";
	}
};

int main()
{
	Point pixel(30, 40);	// �ʱ� �ȼ� ��ǥ ����
	int brightness = 10;	// ��� ������ ����

	pixel = pixel + brightness;		//������ �����ε��Ͽ� �ȼ� ��ǥ�� ��� ���� 

	cout << "���ο� �ȼ� ��ǥ : ";
	pixel.print();	// (40, 50)

	return 0;
}