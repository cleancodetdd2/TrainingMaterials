#include <iostream>
using std::cin; using std::cout; using std::endl;

typedef long long ll;

class Account {
public:
	//�������
	char accId[15];
	char name[20];
	char pw[6];
	ll balance;

	//����Լ�
	ll deposite(ll increase) {
		balance += increase;
		return balance;
	}

	ll withdraw(ll decrease) {
		balance -= decrease;
		return balance;
	}

	void balanceCheck() {
		cout << name << " ������ ���� �ܾ��� " << balance << "�� �Դϴ�.\n";
	}
};


int main()
{
	Account acc = { "123-34567-123", "�Ż��Ӵ�", "1234", 100000 };
	acc.balanceCheck();

	cout << "�Ա� �� ���� �ܾ��� " << acc.deposite(5000) << "�Դϴ�. \n";
	cout << "��� �� ���� �ܾ��� " << acc.withdraw(2000) << "�Դϴ�. \n";

	return 0;
}