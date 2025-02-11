#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using std::cin; using std::cout; using std::endl;

//문자열 클래스
class String {
private:
	char* mStr;		// 동적 할당된 문자열의 주소를 저장하는 포인터
	int mLength;	// 동적 할당된 문자열의 길이를 저장하는 변수

public:
	String() : mStr(NULL), mLength(0) {
		cout << "1.생성자 호출\n";
	}
	
	String(const char* str) {
		this->mLength = strlen(str);		// 문자열의 길이 저장
		this->mStr = new char[mLength + 1];	// 동적 할당
		strcpy(mStr, str);					// 동적 메모리에 문자열 복사
		cout << "2.생성자 호출\n";
	}

	String(const String& ref) {
		this->mLength = ref.mLength;
		this->mStr = new char[mLength + 1];		// 동적 할당
		strcpy(this->mStr, ref.mStr);
		cout << "3.[깊은 복사]를 수행하는 복사 생성자 호출\n";
	}

	~String() {
		delete[] mStr;	// mStr이 가리키는 메모리 제거 
		cout << "~소멸자 : 동적으로 할당된 문자열을 제거";
		cout << "\n";
	}

	char* GetString() const {
		return mStr;		// 동적 메모리의 주소 리턴
	}

};

int main()
{
	//String s1 = "Hello";
	String s1("Hello");
	String s2("Time and tide wait for no man");
	//String s3 = s2;
	String s3(s1);		// 복사 생성자

	cout << "s1 = " << s1.GetString() << endl;
	cout << "s2 = " << s2.GetString() << endl;
	cout << "s3 = " << s3.GetString() << endl;

	return 0;
}