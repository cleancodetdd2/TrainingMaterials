#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class Person {
private:
	string name;
public:
	Person() { this->name = "�̼���"; }
	Person(string name) : name(name) { }
	Person operator +(const Person& other) {
		return Person(name + " & " + other.name);
	}
	void showName() { cout << "�̸� : " << name << '\n'; }
};

int main()
{
	Person person1;
	Person person2("�Ż��Ӵ�");
	Person result = person1 + person2;
	result.showName();

	return 0;
}