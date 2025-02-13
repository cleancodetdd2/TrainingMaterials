#include <iostream>

using std::cin; using std::cout; using std::endl; using std::string;

class Base {
public:
	int a = 10;			//public ���
protected:
	int b = 20;			//protected ���
private:
	int c = 30;			//private ��� 
};

// 1. public ���
class Derived1 : public Base {
public:
	void show() {
		cout << "Derived1 - public ���" << endl;
		cout << "a: " << a << endl;		//���� (public ����)
		cout << "b: " << b << endl;		//���� (protected ����)
		//cout << "c: " << c << endl;		//�Ұ��� (private�� ��ӵ��� ����)
	}
};

// 2. protected ���
class Derived2 : protected Base {
public:
	void show() {
		cout << "Derived2 - protected ���" << endl;
		cout << "a: " << a << endl;		//���� (protected ����)
		cout << "b: " << b << endl;		//���� (protected ����)
		//cout << "c: " << c << endl;		//�Ұ��� (private�� ��ӵ��� ����)
	}
};

// 3. private ���
class Derived3 : private Base {
public:
	void show() {
		cout << "Derived3 - private ���" << endl;
		cout << "a: " << a << endl;		//���� (private ����)
		cout << "b: " << b << endl;		//���� (private ����)
		//cout << "c: " << c << endl;		//�Ұ��� (private�� ��ӵ��� ����)
	}
};

int main()
{
	Derived1 d1;
	d1.show();
	cout << "�ܺο��� a ����: " << d1.a << endl; 

	Derived2 d2;
	d2.show();
	//cout << "�ܺο��� a ����: " << d2. << endl;

	Derived3 d3;
	d3.show();
	//cout << "�ܺο��� a ����: " << d3. << endl;

	return 0;
}