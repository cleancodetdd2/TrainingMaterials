#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using std::cin; using std::cout; using std::endl;

int main()
{
	std::vector<int> vector;		// 동적 배열 컨테이너 객체 생성
	vector.push_back(10);			// 요소 추가
	vector.push_back(20);
	vector.push_back(-1);

	cout << "vector (순서 유지)" << endl;
	for (int num : vector)
		cout << num << " ";
	cout << "\n" << endl;

	std::set<int> set;				// 정렬된 상태를 유지하는 컨테이너 객체 생성
	set.insert(10);					// 요소 추가 (자동 정렬)
	set.insert(20);
	set.insert(-1);

	cout << "set (자동 정렬)" << endl;
	for (int num : set)				
		cout << num << " ";			// 정렬된 상태로 출력 (-1, 10, 20)
	cout << "\n" << endl;

	std::unordered_set<int> uset;	// 정렬되지 않은 상태 유지하는 컨테이너 객체 생성
	uset.insert(10);
	uset.insert(20);
	uset.insert(-1);

	cout << "unordered set (순서 보장 안됨)" << endl;
	for (int num : uset)
		cout << num << " ";			
	cout << "\n" << endl;

	cout << "\n------------------순회하는 코드----------------" << endl;
	std::vector<int> nums{ 9, 2, 8, 4 };	// 동적으로 관리되는 배열처럼 동작함

	cout << "인덱스를 이용한 접근 " << endl;
	for (size_t i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << "\n" << endl;

	cout << "범위 기반 for문" << endl;
	for (int num : nums)
		cout << num << " ";
	cout << "\n" << endl;

	cout << "이터레이터를 이용한 순회" << endl;
	for (std::vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
		cout << *iter << " ";		// 이터레이터가 가리키는 값 출력
	cout << "\n\n";
	return 0;
}