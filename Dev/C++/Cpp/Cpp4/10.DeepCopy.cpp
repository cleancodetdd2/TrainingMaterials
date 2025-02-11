#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using std::cin; using std::cout; using std::endl;

//���ڿ� Ŭ����
class String {
private:
	char* mStr;		// ���� �Ҵ�� ���ڿ��� �ּҸ� �����ϴ� ������
	int mLength;	// ���� �Ҵ�� ���ڿ��� ���̸� �����ϴ� ����

public:
	String() : mStr(NULL), mLength(0) {
		cout << "1.������ ȣ��\n";
	}
	
	String(const char* str) {
		this->mLength = strlen(str);		// ���ڿ��� ���� ����
		this->mStr = new char[mLength + 1];	// ���� �Ҵ�
		strcpy(mStr, str);					// ���� �޸𸮿� ���ڿ� ����
		cout << "2.������ ȣ��\n";
	}

	String(const String& ref) {
		this->mLength = ref.mLength;
		this->mStr = new char[mLength + 1];		// ���� �Ҵ�
		strcpy(this->mStr, ref.mStr);
		cout << "3.[���� ����]�� �����ϴ� ���� ������ ȣ��\n";
	}

	~String() {
		delete[] mStr;	// mStr�� ����Ű�� �޸� ���� 
		cout << "~�Ҹ��� : �������� �Ҵ�� ���ڿ��� ����";
		cout << "\n";
	}

	char* GetString() const {
		return mStr;		// ���� �޸��� �ּ� ����
	}

};

int main()
{
	//String s1 = "Hello";
	String s1("Hello");
	String s2("Time and tide wait for no man");
	//String s3 = s2;
	String s3(s1);		// ���� ������

	cout << "s1 = " << s1.GetString() << endl;
	cout << "s2 = " << s2.GetString() << endl;
	cout << "s3 = " << s3.GetString() << endl;

	return 0;
}