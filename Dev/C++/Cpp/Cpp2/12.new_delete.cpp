#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int num;
	cout << "학생 수 입력 : ";
	cin >> num;

	//int score[num];  // 배열은 정적 할당이 되야 함 -- 컴파일시 메모리 크기가 결정되야 함 
	int* score = new int[num]; //실행 중(run-time)에 메모리를 할당(동적 할당) => heap 영역 
	double total = 0;
	for (int i = 0; i < num; i++)
	{
		cout << i + 1 << "번째 점수 입력 : ";
		cin >> score[i];
		total += score[i];
	}

	cout << num << "명 학생의 점수 평균은 " << total / num << "입니다.\n";

	delete[] score;  //동적 할당된 메모리는 반드시 제거돼야 함 

	return 0;
}