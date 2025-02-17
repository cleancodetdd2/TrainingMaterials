// Ŭ���� ���, �����Լ�, override, �������ε�, ������

#include <iostream>

using std::cin; using std::cout; using std::endl;

class Base
{
public:
	Base();
	Base(int num);
	virtual void Print();		// �����Լ�

	int GetNum() const;

private:
	int num;
};

Base::Base() : num(0) {}
Base::Base(int num) : num(num) {}

void Base::Print()
{
	cout << "Base::Print()" << endl;
	cout << "num: " << num << endl;
}

int Base::GetNum() const
{
	return num;
}


class ChildA : public Base
{
public:
	ChildA(int aa);
	ChildA(int, int);

	void Print() override;		// override�� C++11 ���� �߰���

private:
	int aa;
};

ChildA::ChildA(int aa = 0) : aa(aa), Base(0) {}
ChildA::ChildA(int num, int aa) : Base(num), aa(aa) {}

void ChildA::Print()
{
	cout << "ChildA::Print()" << endl;
	cout << "num: " << GetNum() << endl;
	cout << "aa: " << aa << endl;
}

int main()
{
	Base base = Base(100);
	base.Print();
	cout << endl;

	ChildA childA = ChildA(200, 300);
	childA.Print();
	cout << endl;

	Base* childB = new ChildA(1000, 1000);		//���� ���ε�
	childB->Print();
	delete childB;

	return 0;
}