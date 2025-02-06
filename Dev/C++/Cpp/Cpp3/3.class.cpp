#include <iostream>
using std::cin; using std::cout; using std::endl;

typedef long long ll;

class Account {
public:
	//멤버변수
	char accId[15];
	char name[20];
	char pw[6];
	ll balance;

	//멤버함수
	ll deposite(ll increase) {
		balance += increase;
		return balance;
	}

	ll withdraw(ll decrease) {
		balance -= decrease;
		return balance;
	}

	void balanceCheck() {
		cout << name << " 고객님의 현재 잔액은 " << balance << "원 입니다.\n";
	}
};


int main()
{
	Account acc = { "123-34567-123", "신사임당", "1234", 100000 };
	acc.balanceCheck();

	cout << "입금 후 현재 잔액은 " << acc.deposite(5000) << "입니다. \n";
	cout << "출금 후 현재 잔액은 " << acc.withdraw(2000) << "입니다. \n";

	return 0;
}