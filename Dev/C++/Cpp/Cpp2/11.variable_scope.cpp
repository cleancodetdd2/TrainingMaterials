#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int global = 1;			//전역변수

void func(int arg) {	//매개변수
	int x = 1;			//지역변수
	static int sta = 1;	//정적변수 = 지역변수(해당블록내에서 사용) + 전역변수(변수의 scope)

	global++;
	sta++;
	x++;

	cout << global << ", " << sta << ", " << x << endl;
}

void func2() {
	global = 100;
	//sta = 200;  //error
	cout << "global = " << global << endl;
}

int main()
{
	int a = 3;	//지역변수

	{
		int b = 7;		//지역변수
		int c = 9;		//지역변수
	}

	func(100);
	func(200);
	func(300);
	func2();
	cout << "global = " << global << endl;

	return 0;
}