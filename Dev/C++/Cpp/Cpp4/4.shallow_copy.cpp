#include <iostream>

using std::cin; using std::cout; using std::endl;

class MyClass
{
private:
	int size;
	int* data;

public:
	MyClass(int n) : size(n), data(new int[n]) {
		cout << "������ : " << size << "���� int �� �޸� �Ҵ�\n";
	}
	~MyClass() {
		cout << "�Ҹ��� : �޸� ����\n";
		delete[] data;
	}
};

int main()
{
	MyClass m1(5);
	MyClass m2 = m1;		// ���� ������ ȣ�� (�⺻������ ���� ����)

	return 0;
}