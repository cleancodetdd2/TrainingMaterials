#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

class Human {
protected:				// 자식클래스에서도 접근 가능
	string mName = "";
	int mAge = 0;
public:
	Human() { cout << "1. 부모 생성자(Human 기본 생성자 호출)\n"; }
	Human(string name, int age) {
		this->mName = name;
		this->mAge = age;
		cout << "2. 부모 생성자(Human(string, int) 호출)\n";
	}
	Human(const Human& other) {
		this->mName = other.mName;
		this->mAge = other.mAge;
		cout << "3. 부모 복사 생성자 호출(Human 복사 생성자)\n";
	}
	~Human() { cout << "~부모 소멸자 (Human 소멸자 호출)\n"; }

	inline string GetName() const { return mName; }	//inline 함수는 함수의 코드를 호출한 위치에 직접 삽입함
	inline int GetAge() const { return mAge; }
	inline void SetName(string name) { mName = name; }
	inline void SetAge(int age) { mAge = age; }

	string ToString() {
		return "이름: " + mName + ", 나이: " + std::to_string(mAge);
	}
};

class Student : public Human {
protected:
	string mNo = "";
	string mMajor = "";
public:
	Student() { cout << "1. 자식 생성자 (Student 기본 생성자 호출)"; }
	Student(string no, string major, string name, int age) : Human(name, age) {
		mNo = no;
		mMajor = major;
		cout << "2. 자식 생성자 (Student(no, major, name, age) 호출)\n";
	}
	Student(const Student& other) : Human(other) {	// 부모 복사 생성자 호출
		mNo = other.mNo;
		mMajor = other.mMajor;
		cout << "3. 자식 복사 생성자 (Student 복사 생성자)\n";
	}
	~Student() { cout << "~자식 소멸자 (Student 소멸자 호출)\n"; }

	inline string GetNo() const { return mNo; }	//inline 함수는 함수의 코드를 호출한 위치에 직접 삽입함
	inline string GetMajor() const { return mMajor; }
	inline void SetNo(string no) { mNo = no; }
	inline void SetMajor(string major) { mMajor = major; }

	string ToString() {
		return Human::ToString() + ", 학번: " + mNo + ", 전공: " + mMajor;
	}

	void ShowStudentInfo() const {
		cout << "학번:" << mNo << endl;
		cout << "전공:" << mMajor << endl;

		cout << "이름:" << mName << endl;
		cout << "나이:" << mAge << endl;
	}
};

int main()
{
	Student s1("25-1234", "AI공학과", "이순신", 19);
	
	Student s2(s1);  //Student s2 = s1;

	cout << "\n--- s1 정보 ---\n";
	s1.ShowStudentInfo();
	cout << "\n--- s2 정보 ---\n";
	s2.ShowStudentInfo();

	return 0;		//main() 함수 종료 => 객체 소멸
}