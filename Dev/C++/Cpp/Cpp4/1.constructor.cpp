#include <iostream>

using std::cin; using std::cout; using std::endl;

class DataContainer {
public:
	//기본 생성자
	DataContainer() : primaryValue(0), secondaryValue(0) {
		cout << "기본 생성자 호출 : " << primaryValue << secondaryValue << "\n\n";
	}
	//단일 매개변수 생성자
	DataContainer(int primary) : primaryValue(primary), secondaryValue(20){
		cout << "1개 인자 생성자 호출 : " << primaryValue << secondaryValue << "\n\n";
	}
	//두 개의 매개변수를 받는 생성자
	DataContainer(int primary, int secondary) : primaryValue(primary), secondaryValue(secondary){
		cout << "2개 인자 생성자 호출 : " << primaryValue << secondaryValue << "\n\n";
	}

	//객체 정보 출력하는 함수
	void printInfo() const {
		cout << "primaryValue : " << primaryValue << ", secondaryValue : " << secondaryValue << endl;
	}
	

private:
	int primaryValue;
	int secondaryValue;
};

int main()
{
	DataContainer obj1;
	obj1.printInfo();

	DataContainer obj2(1000);
	obj2.printInfo();

	DataContainer obj3(100, 200);
	obj3.printInfo();

	return 0;
}