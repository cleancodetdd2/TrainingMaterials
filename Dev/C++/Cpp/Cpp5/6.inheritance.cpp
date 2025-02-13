#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

class Person {
private:
	string name;	
public:
	Person(string name) : name(name) {}
	string getName() { return this->name; }
	void showName() { cout << "�̸� : " << getName() << "\n"; }
};

class Temp {
public:
	void showTemp() { cout << "�ӽ� �θ� Ŭ�����Դϴ�.\n"; }
};

class Student : Person, public Temp {
private:
	int studentID;
public:
	Student(int studentID, string name) : Person(name) {
		this->studentID = studentID;
	}
	void show() {
		cout << "�л� ��ȣ : " << this->studentID << '\n';
		cout << "�л� �̸� : " << this->getName() << '\n';
	}
};

int main() {
	Student student1(1, "�̼���");
	student1.show();
	student1.showTemp();

	return 0;
}