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
	int len = strlen(name);			// name�� ���� ���� 
	this->name = new char[len + 1];	// name ���ڿ� ���� �Ҵ�
	strcpy(this->name, name);		// name�� ���ڿ� ���� 
}

Person::Person(const Person& person) {		// ���� ������
	this->id = person.id;
	int len = strlen(person.name);				// name�� ���� ���� 
	this->name = new char[len + 1];		// name ���ڿ� ���� �Ҵ�
	strcpy(this->name, person.name);		// name�� ���ڿ� ���� 
	cout << "���� ������ ����. ���� ��ü�� �̸� " << this->name << endl;
}

Person::~Person() {
	if (name)
		delete[] name;	// ���� �Ҵ� �޸� ���� 
}

void Person::changeName(const char* name) {	//�̸� ����
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}




int main()
{
	Person person1(1, "lee");		// ������ ȣ��
	Person person2(person1);		// ���� ������ ȣ��

	cout << "person2 ��ü ���� ��" << endl;
	person1.showInfo();
	person2.showInfo();

	person2.changeName("won");
	cout << "person2 �̸��� won���� ������ ��" << endl;
	person1.showInfo();
	person2.showInfo();

	return 0;
}