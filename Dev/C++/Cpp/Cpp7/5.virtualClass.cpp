#include <iostream>

using std::cin; using std::cout; using std::endl;

class Calculator {
public:
	virtual int add(int a, int b) = 0;			// 두정수의 합 리턴
	virtual int substract(int a, int b) = 0;	// 두정수의 차 리턴
	virtual double average(int a[], int size) = 0;	// 배열 a의 평균 리턴
};

class SpeedCalcu : public Calculator {
public:
	int add(int a, int b) { return a + b; }
	int substract(int a, int b) { return a - b; }
	double average(int a[], int size) {
		double sum = 0;
		for (int i = 0; i < size; i++)
			sum += a[i];
		return sum / size;
	}
};

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	Calculator* p = new SpeedCalcu();
	cout << p->add(5, 6) << endl;
	cout << p->substract(5, 6) << endl;
	cout << p->average(a, 5) << endl;

	delete p;

	return 0;
}