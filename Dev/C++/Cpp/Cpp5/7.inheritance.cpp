#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

class Human {
protected:				// �ڽ�Ŭ���������� ���� ����
	string mName = "";
	int mAge = 0;
public:
	Human() { cout << "1. �θ� ������(Human �⺻ ������ ȣ��)\n"; }
	Human(string name, int age) {
		this->mName = name;
		this->mAge = age;
		cout << "2. �θ� ������(Human(string, int) ȣ��)\n";
	}
	Human(const Human& other) {
		this->mName = other.mName;
		this->mAge = other.mAge;
		cout << "3. �θ� ���� ������ ȣ��(Human ���� ������)\n";
	}
	~Human() { cout << "~�θ� �Ҹ��� (Human �Ҹ��� ȣ��)\n"; }

	inline string GetName() const { return mName; }	//inline �Լ��� �Լ��� �ڵ带 ȣ���� ��ġ�� ���� ������
	inline int GetAge() const { return mAge; }
	inline void SetName(string name) { mName = name; }
	inline void SetAge(int age) { mAge = age; }

	string ToString() {
		return "�̸�: " + mName + ", ����: " + std::to_string(mAge);
	}
};

class Student : public Human {
protected:
	string mNo = "";
	string mMajor = "";
public:
	Student() { cout << "1. �ڽ� ������ (Student �⺻ ������ ȣ��)"; }
	Student(string no, string major, string name, int age) : Human(name, age) {
		mNo = no;
		mMajor = major;
		cout << "2. �ڽ� ������ (Student(no, major, name, age) ȣ��)\n";
	}
	Student(const Student& other) : Human(other) {	// �θ� ���� ������ ȣ��
		mNo = other.mNo;
		mMajor = other.mMajor;
		cout << "3. �ڽ� ���� ������ (Student ���� ������)\n";
	}
	~Student() { cout << "~�ڽ� �Ҹ��� (Student �Ҹ��� ȣ��)\n"; }

	inline string GetNo() const { return mNo; }	//inline �Լ��� �Լ��� �ڵ带 ȣ���� ��ġ�� ���� ������
	inline string GetMajor() const { return mMajor; }
	inline void SetNo(string no) { mNo = no; }
	inline void SetMajor(string major) { mMajor = major; }

	string ToString() {
		return Human::ToString() + ", �й�: " + mNo + ", ����: " + mMajor;
	}

	void ShowStudentInfo() const {
		cout << "�й�:" << mNo << endl;
		cout << "����:" << mMajor << endl;

		cout << "�̸�:" << mName << endl;
		cout << "����:" << mAge << endl;
	}
};

int main()
{
	Student s1("25-1234", "AI���а�", "�̼���", 19);
	
	Student s2(s1);  //Student s2 = s1;

	cout << "\n--- s1 ���� ---\n";
	s1.ShowStudentInfo();
	cout << "\n--- s2 ���� ---\n";
	s2.ShowStudentInfo();

	return 0;		//main() �Լ� ���� => ��ü �Ҹ�
}