#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int a = 10;
	auto b = a;
	//auto c;  //error - auto Ÿ���� ������ ���� �Ҽ� ���� 
	auto c = 3.4;

	cout << a << ", " << b << endl;
	cout << typeid(a).name() << ", " << typeid(b).name() << ", " << typeid(c).name() << endl;

	return 0;
}