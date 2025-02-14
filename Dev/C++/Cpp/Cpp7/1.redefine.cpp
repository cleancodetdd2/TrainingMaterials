#include <iostream>

using std::cin; using std::cout; using std::endl;

class Base {
public:
	void func() { cout << "Base::func() 호출" << endl; }
};

class Derived : public Base {
public:
	void func() { cout << "Derived::func() 호출" << endl; }
};

int main()
{
	Derived d, * pDer;
	pDer = &d;		
	pDer->func();

	Base* pBase;
	pBase = pDer;
	pBase->func();

	return 0;
}