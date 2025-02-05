#include <iostream>
#include <string>

using namespace std;

struct Student {
	string name = "";
	int age = 0;
	double score = 0.0;
};

//������ �̿��� �л����� �Է� �Լ�
void inputStudent(Student& stdudent)
{
	cout << "�̸� �Է�: ";
	cin >> stdudent.name;
	cout << "���� �Է�: ";
	cin >> stdudent.age;
	cout << "���� �Է�: ";
	cin >> stdudent.score;
}

// �л� ���� ��� �Լ� (const ���� ���)
void printStudent(const Student& student)
{
	cout << "\n�л� ����" << endl;
	cout << "�̸� : " << student.name << endl;
	cout << "���� : " << student.age << endl;
	cout << "���� : " << student.score << endl;
 }

int main()
{
	Student student;
	inputStudent(student);	//������ ����
	printStudent(student);  //const ������ ����

	return 0;
}