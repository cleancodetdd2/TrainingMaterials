#include <iostream>
#include <typeinfo>		//타입 정보를 확인

using std::cin; using std::cout; using std::endl;

// 함수 템플릿(두 값 중 작은 값을 반환하는 함수)
template<typename T>
T Min(T a, T b)
{
	cout << "\n Min 함수 호출, Type: " << typeid(T).name() << endl;	// 타입 정보 출력
	return (a > b) ? b : a;
}

// 함수 템플릿 (두 값을 교환하는 함수)
template<typename T>
void Swap(T& refA, T& refB)
{
	cout << "\n Swap 함수 호출, Type: " << typeid(T).name() << endl;	// 타입 정보 출력
	T temp = refB;
	refB = refA;
	refA = temp;
}

//구조체 (Min함수 테스트 위함)
struct SData
{
	int i;
	SData(int _i) { this->i = _i; }		// 생성자 정의

	// 비교 연산자 > 오버로딩 
	bool operator > (const SData& refSData) const
	{
		cout << "operator > 연산자 호출" << endl;
		return (i > refSData.i);		// 두 객체의 i값을 비교하여 반환
	}
};

//클래스 (Swap 함수 테스트 위함)
class CData
{
private:
	int num;
	float fNum;

public:
	CData() : num(0), fNum(0.0f) {}		//기본 생성자
	CData(int num, float fNum) : num(num), fNum(fNum) {}	// 매개변수를 받는 생성자
	CData(const CData& refCdata)							// 복사 생성자
	{
		cout << "CData(const CData& refCdata) 호출" << endl;
		this->num = refCdata.num;
		this->fNum = refCdata.fNum;
	}
	~CData() {}

	void OutPut() const
	{
		cout << "num: " << num << ", fNum : " << fNum << endl;
	}

	CData& operator=(const CData& refCdata)
	{
		if (this != &refCdata)
		{
			this->num = refCdata.num;
			this->fNum = refCdata.fNum;
		}
		return *this;
	}
};

int main()
{
	int num1 = 10, num2 = 20;
	float fNum1 = 10.0f, fNum2 = 20.0f;

	//SData 객체 생성
	SData sData1(10);
	SData sData2(90);

	// 함수 템플릿 (기본 데이터 타입)
	cout << "\nMin(num1, num2) : " << Min(num1, num2) << endl;
	cout << "\nMin(fNum1, fNum2) : " << Min(fNum1, fNum2) << endl;
	cout << "\nMin(sData1, sData2) : " << Min(sData1, sData2).i << endl;

	cout << "\n------------------class----------------" << endl;
	CData cData1(10, 10.0f);
	CData cData2(90, 90.0f);

	CData cData3(cData2);
	cData3.OutPut();		// 복사 생성된 객체 출력

	cout << "\n Swap() 실행 전" << endl;
	cData1.OutPut();
	cData2.OutPut();

	Swap(cData1, cData2);
	cout << "\n Swap() 실행 후" << endl;
	cData1.OutPut();
	cData2.OutPut();


	return 0;
}