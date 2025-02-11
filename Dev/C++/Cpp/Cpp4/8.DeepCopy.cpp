#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using std::cout; using std::endl;

class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name);
	Person(const Person& person);
	~Person();
	void changeName(const char* name);
	void showInfo() { cout << id << ", " << name << endl; }
};

Person::Person(int id, const char* name) {
	this->id = id;
	int len = strlen(name);			// name의 문자 갯수 
	this->name = new char[len + 1];	// name 문자열 공간 할당
	strcpy(this->name, name);		// name에 문자열 복사 
}

Person::Person(const Person& person) {		// 복사 생성자
	this->id = person.id;
	int len = strlen(person.name);				// name의 문자 갯수 
	this->name = new char[len + 1];		// name 문자열 공간 할당
	strcpy(this->name, person.name);		// name에 문자열 복사 
	cout << "복사 생성자 실행. 원본 객체의 이름 " << this->name << endl;
}

Person::~Person() {
	if (name)
		delete[] name;	// 동적 할당 메모리 삭제 
}

void Person::changeName(const char* name) {	//이름 변경
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}




int main()
{
	Person person1(1, "lee");		// 생성자 호출
	Person person2(person1);		// 복사 생성자 호출

	cout << "person2 객체 생성 후" << endl;
	person1.showInfo();
	person2.showInfo();

	person2.changeName("won");
	cout << "person2 이름을 won으로 변경한 후" << endl;
	person1.showInfo();
	person2.showInfo();

	return 0;
}