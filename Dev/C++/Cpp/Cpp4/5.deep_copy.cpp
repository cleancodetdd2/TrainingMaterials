#include <iostream>

using std::cin; using std::cout; using std::endl;

class MyClass
{
private:
	int size;
	int* data;

public:
	MyClass(int n) : size(n), data(new int[n]) {
		for (int i = 0; i < size; i++)
			data[i] = i;		// 배열 초기화
		cout << "생성자 : " << size << "개의 int 형 메모리 할당\n";
	}

	//복사 생성자 (깊은 복사)
	MyClass(const MyClass& other) : size(other.size), data(new int[other.size]) {
		for (int i = 0; i < size; i++)
			data[i] = other.data[i];

		cout << "복사 생성자 호출(깊은 복사 수행)\n\n";
	}

	~MyClass() {
		cout << "소멸자 : 메모리 해제\n";
		delete[] data;
	}

	void printData() const
	{
		for (int i = 0; i < size; i++)
			cout << data[i] << " ";
		cout << endl;
		cout << "\n";
	}
};

int main()
{
	MyClass m1(5);
	m1.printData();

	MyClass m2(m1);		//복사 생성자 호출
	m2.printData();

	MyClass m3(3);
	m3.printData();

	return 0;
}