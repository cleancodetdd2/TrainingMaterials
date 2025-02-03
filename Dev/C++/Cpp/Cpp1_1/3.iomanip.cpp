#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << left;		//출력 정렬을 왼쪽 정렬로 설정(기본값은 오른쪽 정렬)
	for (int i = 1; i <= 100; i++)
		cout << setw(8) << i;
	cout << endl;	// 개행하여 다음 줄로 이동 

	cout << "\n";

	char str[255];	// 배열이름은 포인터 (str == &str[0])
	cout << "문자열 입력 : ";
	cin >> str;	// 입력 (주소부터 차례대로 저장한 후, 끝에 널문자('\0')가 추가됨
	cout << "입력 받은 문자열은 " << str << "입니다.\n";	// 널문자 이전까지 출력


	return 0;
}