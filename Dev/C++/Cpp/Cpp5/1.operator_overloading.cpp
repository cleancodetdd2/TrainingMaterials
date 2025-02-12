#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class Person {
private:
	string name;
public:
	Person() { this->name = "이순신"; }
	Person(string name) : name(name) { }
	Person operator +(const Person& other) {
		return Person(name + " & " + other.name);
	}
	void showName() { cout << "이름 : " << name << '\n'; }
};

int main()
{
	Person person1;
	Person person2("신사임당");
	Person result = person1 + person2;
	result.showName();

	return 0;
}