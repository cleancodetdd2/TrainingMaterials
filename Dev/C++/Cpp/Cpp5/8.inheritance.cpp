#include <iostream>

using std::cin; using std::cout; using std::endl; using std::string;

class Base {
public:
	int a = 10;			//public 멤버
protected:
	int b = 20;			//protected 멤버
private:
	int c = 30;			//private 멤버 
};

// 1. public 상속
class Derived1 : public Base {
public:
	void show() {
		cout << "Derived1 - public 상속" << endl;
		cout << "a: " << a << endl;		//가능 (public 유지)
		cout << "b: " << b << endl;		//가능 (protected 유지)
		//cout << "c: " << c << endl;		//불가능 (private은 상속되지 않음)
	}
};

// 2. protected 상속
class Derived2 : protected Base {
public:
	void show() {
		cout << "Derived2 - protected 상속" << endl;
		cout << "a: " << a << endl;		//가능 (protected 변경)
		cout << "b: " << b << endl;		//가능 (protected 유지)
		//cout << "c: " << c << endl;		//불가능 (private은 상속되지 않음)
	}
};

// 3. private 상속
class Derived3 : private Base {
public:
	void show() {
		cout << "Derived3 - private 상속" << endl;
		cout << "a: " << a << endl;		//가능 (private 변경)
		cout << "b: " << b << endl;		//가능 (private 변경)
		//cout << "c: " << c << endl;		//불가능 (private은 상속되지 않음)
	}
};

int main()
{
	Derived1 d1;
	d1.show();
	cout << "외부에서 a 접근: " << d1.a << endl; 

	Derived2 d2;
	d2.show();
	//cout << "외부에서 a 접근: " << d2. << endl;

	Derived3 d3;
	d3.show();
	//cout << "외부에서 a 접근: " << d3. << endl;

	return 0;
}