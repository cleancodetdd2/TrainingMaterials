/*
	�׷��� ��ǥ ��� (2D ����, CAD ���α׷�)
	 - ���� ĳ���� ��ġ ��� 
*/
#include <iostream>
using std::cin; using std::cout; using std::endl;

//��ǥ�� ������� ���� �ִ� Point Ŭ����
class Point {
public:
	int x, y;	// ��ǥ��

	Point(int x = 0, int y = 0) : x(x), y(y) { }	// ������ (��ǥ���� 0���� �ʱ�ȭ)

	Point& operator += (const Point& ref) {		// += ������ �����ε� (��ǥ �̵� ���)
		this->x += ref.x;		// ���� ��ü�� x ��ǥ�� ref ��ü�� x���� ���� 
		this->y += ref.y;		// ���� ��ü�� y ��ǥ�� ref ��ü�� y���� ���� 
		return *this;			// �ڱ� �ڽ��� ������ ��ȯ�Ͽ� ĳ������ �������� ��ġ�� ���� ����
	}

	void print() {		// ��ǥ���� ���
		cout << "(" << x << ", " << y << ")\n";
	}
};

int main()
{
	Point player(10, 20);		// �÷��̾� �ʱ� ��ġ(10, 20)
	Point movePlayer(5, -3);	// �÷��̾� �̵� ����(x�� +5, y�� -3)

	player += movePlayer;		// player.operator+=(movePlayer);

	cout << "�÷��̾� �� ��ġ : ";
	player.print();				// �÷��̾��� ���ο� ��ġ

	return 0;
}