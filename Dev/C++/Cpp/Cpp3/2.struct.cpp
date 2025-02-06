#include <iostream>
using std::cin; using std::endl; using std::cout;

typedef long long ll;

struct Account {
	char accId[15];		//계좌번호 15자리
	char name[20];
	char pw[5];
	ll balance;			
};

ll deposite(Account& ref, ll increase);
ll withdraw(Account& ref, ll decrease);
void balanceCheck(Account& ref);

int main()
{
	Account acc = { "123-56787-345", "이순신", "1234", 90000 };	// 구조체 변수 선언 및 초기화

	balanceCheck(acc);

	cout << "입금 후 현재 잔액은 " << deposite(acc, 5000) << "입니다. \n";
	cout << "출금 후 현재 잔액은 " << withdraw(acc, 2000) << "입니다. \n";

	return 0;
}

ll deposite(Account& ref, ll increase) {
	ref.balance += increase;
	return ref.balance;		//잔액 리턴.
}

ll withdraw(Account& ref, ll increase) {
	ref.balance -= increase;
	return ref.balance;		//잔액 리턴.
}

void balanceCheck(Account& ref) {
	cout << ref.name << " 고객님의 현재 잔액은 " << ref.balance << "원 입니다.\n";
}