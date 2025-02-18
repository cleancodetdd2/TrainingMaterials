#include <iostream>
#include <list>
#include <algorithm>

using std::cin; using std::cout; using std::endl;

int main()
{
	// 양방향 연결 리스트 사용
	std::list<int> list0{ 1, 2, 3 };
	std::list<int>::iterator iter = list0.begin();	// 이터레이터를 사용하여 리스트 내 원소 접근
	std::advance(iter, 2);		// 이터레이터를 2칸 전진
	cout << "list0의 세 번째 원소 : " << *iter << endl;

	return 0;
}