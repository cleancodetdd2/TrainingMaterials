#include <iostream>

using std::cout; using std::endl;

int main()
{
	int a = 7, b = 0;

	try {
		if (b == 0)
			throw "0���� ���� �� �����ϴ�.";
		cout << a / b << endl;
	}
	catch (const char* str) {
		cout << str << endl;
	}

	return 0;
}