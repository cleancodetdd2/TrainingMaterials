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
		this->name = name;	//�ڱ� �ڽ��� ��� ������ ����
		this->englishScore = englishScore;
		this->mathScore = mathScore;
	}
};

