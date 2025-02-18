#include <iostream>
#include <typeinfo>		//Ÿ�� ������ Ȯ��

using std::cin; using std::cout; using std::endl;

// �Լ� ���ø�(�� �� �� ���� ���� ��ȯ�ϴ� �Լ�)
template<typename T>
T Min(T a, T b)
{
	cout << "\n Min �Լ� ȣ��, Type: " << typeid(T).name() << endl;	// Ÿ�� ���� ���
	return (a > b) ? b : a;
}

// �Լ� ���ø� (�� ���� ��ȯ�ϴ� �Լ�)
template<typename T>
void Swap(T& refA, T& refB)
{
	cout << "\n Swap �Լ� ȣ��, Type: " << typeid(T).name() << endl;	// Ÿ�� ���� ���
	T temp = refB;
	refB = refA;
	refA = temp;
}

//����ü (Min�Լ� �׽�Ʈ ����)
struct SData
{
	int i;
	SData(int _i) { this->i = _i; }		// ������ ����

	// �� ������ > �����ε� 
	bool operator > (const SData& refSData) const
	{
		cout << "operator > ������ ȣ��" << endl;
		return (i > refSData.i);		// �� ��ü�� i���� ���Ͽ� ��ȯ
	}
};

//Ŭ���� (Swap �Լ� �׽�Ʈ ����)
class CData
{
private:
	int num;
	float fNum;

public:
	CData() : num(0), fNum(0.0f) {}		//�⺻ ������
	CData(int num, float fNum) : num(num), fNum(fNum) {}	// �Ű������� �޴� ������
	CData(const CData& refCdata)							// ���� ������
	{
		cout << "CData(const CData& refCdata) ȣ��" << endl;
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

	//SData ��ü ����
	SData sData1(10);
	SData sData2(90);

	// �Լ� ���ø� (�⺻ ������ Ÿ��)
	cout << "\nMin(num1, num2) : " << Min(num1, num2) << endl;
	cout << "\nMin(fNum1, fNum2) : " << Min(fNum1, fNum2) << endl;
	cout << "\nMin(sData1, sData2) : " << Min(sData1, sData2).i << endl;

	cout << "\n------------------class----------------" << endl;
	CData cData1(10, 10.0f);
	CData cData2(90, 90.0f);

	CData cData3(cData2);
	cData3.OutPut();		// ���� ������ ��ü ���

	cout << "\n Swap() ���� ��" << endl;
	cData1.OutPut();
	cData2.OutPut();

	Swap(cData1, cData2);
	cout << "\n Swap() ���� ��" << endl;
	cData1.OutPut();
	cData2.OutPut();


	return 0;
}