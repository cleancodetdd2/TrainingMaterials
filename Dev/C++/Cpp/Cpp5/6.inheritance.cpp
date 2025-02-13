#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

class Person {
private:
	string name;	
public:
	Person(string name) : name(name) {}
	string getName() { return this->name; }
	void showName() { cout << "이름 : " << getName() << "\n"; }
};

class Temp {
public:
	void showTemp() { cout << "임시 부모 클래스입니다.\n"; }
};

class Student : Person, public Temp {
private:
	int studentID;
public:
	Student(int studentID, string name) : Person(name) {
		this->studentID = studentID;
	}
	void show() {
		cout << "학생 번호 : " << this->studentID << '\n';
		cout << "학생 이름 : " << this->getName() << '\n';
	}
};

int main() {
	Student student1(1, "이순신");
	student1.show();
	student1.showTemp();

	return 0;
}