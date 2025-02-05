#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int a[10];

	srand((unsigned int)time(NULL));

	for (auto& elem : a)
		elem = rand() % 10 + 1;

	cout << "랜덤 정수 출력 : ";
	for (const auto& elem : a)
		cout << elem << " ";

	cout << endl;

	return 0;
}