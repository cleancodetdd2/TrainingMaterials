#include <iostream>
#include <string>
#include <vector>	//C++ STL에서 제공하는 동적 배열 사용

using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

class Circle
{
private:
	string name;		// 도넛, 피자, 와플..
	string flavor;		// 맛(초코, 딸기, 치즈..)
	double radius;		// 크기

public:
	Circle(string _name, string _flavor, double _radius)
		: name(_name), flavor(_flavor), radius(_radius) {
		if (radius <= 0)	//반지름이 0 이하일 경우 예외 발생
			throw std::invalid_argument("반지름은 0보다 커야 합니다.");
		cout << name << " 객체 생성 완료!\n";
	}
	//면적 계산 함수
	double getArea() const {
		return 3.141592 * radius * radius;
	}
	//객체 정보 출력하는 함수
	void show() const {
		cout << "이름 : " << name << ", 맛 : " << flavor << ", 면적 : " << getArea() << endl;
	}

};



int main()
{
	// vector를 사용하여 Circle 객체 포인터를 동적으로 관리 
	vector<Circle*> circles;

	cout << "몇 개의 Circle 객체를 생성하시겠습니까? ";
	int count;
	cin >> count;			//생성할 Circle 갯수 입력 받기 

	for (int i = 0; i < count; i++)
	{
		string name, flavor;
		double radius;
		 
		//사용자로부터 객체 속성 입력받기
		cout << "이름 : ";
		cin >> name;
		cout << "맛 : ";
		cin >> flavor;
		cout << "반지름 : ";
		cin >> radius;

		try
		{
			// 동적 할당을 통해 Circle 객체 생성
			Circle* newCircle = new Circle(name, flavor, radius);

			// 생성된 객체의 포인터를 벡터에 저장 (자동으로 크기가 늘어남)
			circles.push_back(newCircle);
		}
		catch (const std::exception& e)
		{
			//예외 발생 시 메시지 출력
			cout << "오류 발생 : " << e.what() << endl;
		}
	}

	cout << "\n 생성된 Circle 정보: \n";
	for (const auto& circle : circles)		// 벡터의 모든 요소를 참조하여 출력
		circle->show();

	for (auto& circle : circles)	// 동적 할당된 객체를 반드시 해제해야 메모리 누수 방지할수 있음
		delete circle;		// new로 생성한 객체 메모리 해제

	circles.clear();		// 메모리 해제 후 추가적인 안전 조치 

	return 0;
}