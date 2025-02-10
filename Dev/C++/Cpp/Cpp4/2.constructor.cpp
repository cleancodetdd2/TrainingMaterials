#include <iostream>

using std::cin; using std::cout; using std::endl;

class NumberHolder {
private:
	int value;	// 값을 저장하는 멤버변수(private 보호)
public:
	// 생성자 : 초기화 리스트를 사용하여 value를 설정
	NumberHolder(int _value) : value(_value) {
		cout << "생성자 호출 : 객체 생성됨 " << endl;
		cout << "\n";
	}

	//소멸자 : 객체가 소멸될 때 호출됨
	~NumberHolder() {
		cout << "소멸자 호출 : 객체 소멸됨" << endl;
	}

	//Getter 함수
	int getValue() const {
		return value;
	}

};

void createTemporaryObject() {
	NumberHolder tempObj2(2);		// 함수 내부에서 지역 객체 생성
	cout << "createTemporaryObject() 내부 : obj2의 값 = " << tempObj2.getValue() << endl;
}

int main()
{
	NumberHolder obj1(1);
	cout << "main() 내부 : obj1의 값 = " << obj1.getValue() << endl;

	createTemporaryObject();
	return 0;
}