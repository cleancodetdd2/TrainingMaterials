#include <iostream>

using std::cout; using std::cin; using std::endl;


int main()
{	
	int value = 3;
	int* ptr = &value;	
	int& ref = value;

	cout << "value 주소 = " << &value << endl;	//value의 주소 출력 
	cout << "value = " << value << endl;	//value의 값 출력
	cout << "포인터 ptr이 참조하는 값 = " << *ptr << endl; //포인터 ptr을 통한 value값 출력
	cout << "레퍼런스 ref = " << ref << endl;	//참조 ref을 통한 value값 출력

	*ptr = 10;	//포인터를 통해 value의 값을 변경
	cout << "\n*ptr = 10 실행 후 : " << *ptr << endl;
	cout << "value = " << value << endl;
	cout << "레퍼런스 ref = " << ref << endl;

	ref = 20;	// 참조 변수를 통해 value 값 변경
	cout << "\nref = 10 실행 후 : " << ref << endl;
	cout << "value = " << value << endl;
	cout << "포인터 ptr이 참조하는 값 = " << *ptr << endl;

	return 0;
}