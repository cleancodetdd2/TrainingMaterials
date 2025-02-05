#include <iostream>
#include <string>

using namespace std;

struct Student {
	string name = "";
	int age = 0;
	double score = 0.0;
};

//참조를 이용한 학생정보 입력 함수
void inputStudent(Student& stdudent)
{
	cout << "이름 입력: ";
	cin >> stdudent.name;
	cout << "나이 입력: ";
	cin >> stdudent.age;
	cout << "점수 입력: ";
	cin >> stdudent.score;
}

// 학생 정보 출력 함수 (const 참조 사용)
void printStudent(const Student& student)
{
	cout << "\n학생 정보" << endl;
	cout << "이름 : " << student.name << endl;
	cout << "나이 : " << student.age << endl;
	cout << "점수 : " << student.score << endl;
 }

int main()
{
	Student student;
	inputStudent(student);	//참조로 전달
	printStudent(student);  //const 참조로 전달

	return 0;
}