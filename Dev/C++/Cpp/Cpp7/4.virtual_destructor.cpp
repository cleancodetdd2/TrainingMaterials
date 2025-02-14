#include <iostream>

using std::cin; using std::cout; using std::endl;

class Base {
public:
	virtual ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
	virtual ~Derived() { cout << "~Derived()" << endl;  }
};

int main() {
	Derived* dp = new Derived();
	Base* bp = new Derived();		//��ĳ����

	delete dp;		// Derived�� �����ͷ� �Ҹ� 
	printf("\n");
	delete bp;		// Base�� �����ͷ� �Ҹ�
}
