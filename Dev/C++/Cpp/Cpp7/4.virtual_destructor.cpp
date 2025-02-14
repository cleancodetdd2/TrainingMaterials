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
	Base* bp = new Derived();		//업캐스팅

	delete dp;		// Derived의 포인터로 소멸 
	printf("\n");
	delete bp;		// Base의 포인터로 소멸
}
