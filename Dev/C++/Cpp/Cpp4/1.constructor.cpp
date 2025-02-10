#include <iostream>

using std::cin; using std::cout; using std::endl;

class DataContainer {
public:
	//�⺻ ������
	DataContainer() : primaryValue(0), secondaryValue(0) {
		cout << "�⺻ ������ ȣ�� : " << primaryValue << secondaryValue << "\n\n";
	}
	//���� �Ű����� ������
	DataContainer(int primary) : primaryValue(primary), secondaryValue(20){
		cout << "1�� ���� ������ ȣ�� : " << primaryValue << secondaryValue << "\n\n";
	}
	//�� ���� �Ű������� �޴� ������
	DataContainer(int primary, int secondary) : primaryValue(primary), secondaryValue(secondary){
		cout << "2�� ���� ������ ȣ�� : " << primaryValue << secondaryValue << "\n\n";
	}

	//��ü ���� ����ϴ� �Լ�
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