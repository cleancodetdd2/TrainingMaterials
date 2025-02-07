/*
	���� ������(Access Modifier)
		- public : ����, ��𼭵� ���� ������ ���
		- private : �����, Ŭ���� �������� ���� ������ ��� 
		- ���� ������ ������ private�� ��.
*/

#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

class Missile
{
public:
	Missile(const string& password) : pw(password) {}

	void pwCheck(const string& inputPw)
	{
		if (pw == inputPw)
			fire();		//�̻��� �߻�
		else
			error();	//��� �޽��� ��� 
	}
private:
	const string pw;		//��й�ȣ
	void fire() {
		cout << "�̻����� �߻��մϴ�!!!\n";
	}
	void error() {
		cout << "��й�ȣ ����!!\n";
	}
};

int main()
{
	//�ν��Ͻ� ����
	Missile mis("2527");
	//����ڿ��� ��й�ȣ �Է¹ޱ�
	string inputPw;
	cout << "��й�ȣ �Է� : ";
	cin >> inputPw;

	mis.pwCheck(inputPw);

	return 0;
}