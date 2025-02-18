#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using std::cin; using std::cout; using std::endl;

int main()
{
	std::vector<int> vector;		// ���� �迭 �����̳� ��ü ����
	vector.push_back(10);			// ��� �߰�
	vector.push_back(20);
	vector.push_back(-1);

	cout << "vector (���� ����)" << endl;
	for (int num : vector)
		cout << num << " ";
	cout << "\n" << endl;

	std::set<int> set;				// ���ĵ� ���¸� �����ϴ� �����̳� ��ü ����
	set.insert(10);					// ��� �߰� (�ڵ� ����)
	set.insert(20);
	set.insert(-1);

	cout << "set (�ڵ� ����)" << endl;
	for (int num : set)				
		cout << num << " ";			// ���ĵ� ���·� ��� (-1, 10, 20)
	cout << "\n" << endl;

	std::unordered_set<int> uset;	// ���ĵ��� ���� ���� �����ϴ� �����̳� ��ü ����
	uset.insert(10);
	uset.insert(20);
	uset.insert(-1);

	cout << "unordered set (���� ���� �ȵ�)" << endl;
	for (int num : uset)
		cout << num << " ";			
	cout << "\n" << endl;

	cout << "\n------------------��ȸ�ϴ� �ڵ�----------------" << endl;
	std::vector<int> nums{ 9, 2, 8, 4 };	// �������� �����Ǵ� �迭ó�� ������

	cout << "�ε����� �̿��� ���� " << endl;
	for (size_t i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << "\n" << endl;

	cout << "���� ��� for��" << endl;
	for (int num : nums)
		cout << num << " ";
	cout << "\n" << endl;

	cout << "���ͷ����͸� �̿��� ��ȸ" << endl;
	for (std::vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
		cout << *iter << " ";		// ���ͷ����Ͱ� ����Ű�� �� ���
	cout << "\n\n";
	return 0;
}