#include <iostream>

using std::cin; using std::cout; using std::endl;

class NumberHolder {
private:
	int value;	// ���� �����ϴ� �������(private ��ȣ)
public:
	// ������ : �ʱ�ȭ ����Ʈ�� ����Ͽ� value�� ����
	NumberHolder(int _value) : value(_value) {
		cout << "������ ȣ�� : ��ü ������ " << endl;
		cout << "\n";
	}

	//�Ҹ��� : ��ü�� �Ҹ�� �� ȣ���
	~NumberHolder() {
		cout << "�Ҹ��� ȣ�� : ��ü �Ҹ��" << endl;
	}

	//Getter �Լ�
	int getValue() const {
		return value;
	}

};

void createTemporaryObject() {
	NumberHolder tempObj2(2);		// �Լ� ���ο��� ���� ��ü ����
	cout << "createTemporaryObject() ���� : obj2�� �� = " << tempObj2.getValue() << endl;
}

int main()
{
	NumberHolder obj1(1);
	cout << "main() ���� : obj1�� �� = " << obj1.getValue() << endl;

	createTemporaryObject();
	return 0;
}