#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

class Student {
private:
	string name;
	int englishScore, mathScore;
	int getSum() { return englishScore + mathScore; }
public:
	Student(string name, int englishScore, int mathScore) {
		this->name = name;	//자기 자신의 멤버 변수에 접근
		this->englishScore = englishScore;
		this->mathScore = mathScore;
	}
};

