#include <iostream>
#include <list>
#include <algorithm>

using std::cin; using std::cout; using std::endl;

int main()
{
	// ����� ���� ����Ʈ ���
	std::list<int> list0{ 1, 2, 3 };
	std::list<int>::iterator iter = list0.begin();	// ���ͷ����͸� ����Ͽ� ����Ʈ �� ���� ����
	std::advance(iter, 2);		// ���ͷ����͸� 2ĭ ����
	cout << "list0�� �� ��° ���� : " << *iter << endl;

	return 0;
}