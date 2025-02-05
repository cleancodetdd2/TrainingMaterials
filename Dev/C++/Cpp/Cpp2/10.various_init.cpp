#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int a = 10;
	int b(10), q(10), r(10);
	int x = { 3 };		// 배열처럼 초기화 가능
	int y{ 3 };
	int z{ 0 };
	int k{ };

	cout << a << ", " << b << ", " << x << ", " << y << ", " << z << ", " << k << endl;

	int c;
	c = 10;
	//int d;
	//d(10); // error -- 소괄호를 이용한 초기화 방식은 선언하면서 초기화 할 때만 가능 

	int arr1[5]{ 1, 2, 3, 4, 5 };
	int arr2[100] = { 0 };
	int arr3[100]{};

	cout << "arr1 : ";
	for (auto elem : arr1)
		cout << elem << " ";
	cout << endl;

	cout << "arr2 : ";
	for (auto elem : arr2)
		cout << elem << " ";
	cout << endl;

	cout << "arr3 : ";
	for (auto elem : arr3)
		cout << elem << " ";
	cout << endl;

	return 0;
}