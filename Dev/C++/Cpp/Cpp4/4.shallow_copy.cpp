#include <iostream>

using std::cin; using std::cout; using std::endl;

class MyClass
{
private:
	int size;
	int* data;

public:
	MyClass(int n) : size(n), data(new int[n]) {
		cout << "생성자 : " << size << "개의 int 형 메모리 할당\n";
	}
	~MyClass() {
		cout << "소멸자 : 메모리 해제\n";
		delete[] data;
	}
};

int main()
{
	MyClass m1(5);
	MyClass m2 = m1;		// 복사 생성자 호출 (기본적으로 얕은 복사)

	return 0;
}