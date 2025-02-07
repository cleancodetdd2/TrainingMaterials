#include <iostream>
using std::cin; using std::cout; using std::endl;

#define OP_COUNT 7		// ���� ���� ���� ����

/*
	������(enum)
	- ���� ������ ��Ÿ��
	- �� �����ڴ� 1���� ������, 1�� ������ ���� ���� ���� 
*/
/*
	mutable
	- const �Լ������� ���� �����ϵ��� mutable ����
	- �Ϲ������� const �Լ��������� ��� ���� ������ �Ұ����� 
	- mutable�� ����ϸ� const �Լ� �������� �ش� ������ ���� ������ �� ����
*/
enum eOperator {
	ADD = 1,
	SUB,
	MUL,
	DIV,
	POWER,			//�ŵ�����
	POWER_OF_TWO	//2�� �ŵ����� 
};

//���� Ŭ���� ���� 
class Calculator {					// const �Լ��� �����Ͽ� ������� ������ �Ұ�����.
public:
	double Add(double d1, double d2) const {
		++mCount[ADD];
		return d1 + d2;
	}

	double Substract(double d1, double d2) const {
		++mCount[SUB];
		return d1 - d2;
	}

	double Multiply(double d1, double d2) const {
		++mCount[MUL];
		return d1 * d2;
	}

	double Divide(double d1, double d2) const {
		if (d2 == 0) {
			cout << "���� : 0���� ���� �� �����ϴ�." << endl;
			return 0;
		}
		++mCount[DIV];
		return d1 / d2;
	}

	// �ŵ����� ���� �Լ� (���� ���� ����ó��)
	std::int64_t Power(int x, int y) const {
		if (y < 0) {
			cout << "���� : ���� ������ �������� �ʽ��ϴ�." << endl;
			return 0;
		}
		++mCount[POWER];

		std::int64_t result = 1;
		for (int i = 0; i < y; i++)
			result *= x;

		return result;
	}

	// 2�� �ŵ����� ���� �Լ�
	std::int64_t PowerOfTwo(int y) const {
		if (y < 0) {
			cout << "���� : ���� ������ �������� �ʽ��ϴ�." << endl;
			return 0;
		}
		++mCount[POWER_OF_TWO];
		return 1LL << y;
	}

	//���� Ƚ���� ����ϴ� �Լ�
	void ShowOperationCount() const {
		cout << "\n\n -- ���� Ƚ�� ��� --\n\n";
		cout << "����: " << mCount[ADD] << "ȸ\n";
		cout << "����: " << mCount[SUB] << "ȸ\n";
		cout << "����: " << mCount[MUL] << "ȸ\n";
		cout << "������: " << mCount[DIV] << "ȸ\n";
		cout << "�ŵ�����: " << mCount[POWER] << "ȸ\n";
		cout << "2�� �ŵ�����: " << mCount[POWER_OF_TWO] << "ȸ\n";
	}

private:	
	mutable int mCount[OP_COUNT] = { 0 };	// ���� Ƚ���� �����ϴ� �迭 
};

//�Է� ���� �Լ� (��ȿ�� ���� �Է��� ���������� �ݺ�)
void GetValidInput(double& num) {
	while (true) {
		cin >> num;
		if (cin.fail()) {	//�Է� �������� ������ ���� ������ ���� �߻�=> true��ȯ(�Է½���)
			cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���." << endl;
			cin.clear();	// cin�� ���� ���¸� �ʱ�ȭ�Ͽ� �ٽ� �Է� ���� �� �ְ� �� 
			cin.ignore(1000, ' '); // �Է� ���ۿ��� �ִ� 1000�� ���� �Ǵ� ���๮�ڰ� ���ö����� ���۸� ���.
		}
		else {
			break;
		}
	}
}

int main()
{
	Calculator calc;		// Calculator ��ü ����

	while (true) {
		cout << "\n\n --- ���� ���α׷� ---\n";
		cout << "1. ����	2. ����	  3. ����   4. ������   5. �ŵ�����    6. 2�� �ŵ�����   0. ����\n";
		cout << "�޴� ���� : ";

		int choice;
		cin >> choice;

		//�߸��� �Է� ó��
		if (cin.fail() || choice < 0 || choice > 6) {
			cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���." << endl;
			cin.clear();
			cin.ignore(1000, ' '); // �Է� ���۸� ��� ���� �Է� ���� ���� 
			continue;
		}

		//���α׷� ���� 
		if(choice == 0) {
			calc.ShowOperationCount();
			return 0;
		}

		double d1, d2, result = 0;
		if (choice == POWER_OF_TWO) {
			cout << "���� �Է� : ";
			GetValidInput(d2);

			result = calc.PowerOfTwo(static_cast<int>(d2));		//2�� �ŵ����� ���(�Ҽ��� ����)
			cout << "2^ " << static_cast<int>(d2) << " = " << result << endl;
		} 
		else {
			cout << "�� ���� �Է� : ";
			GetValidInput(d1);
			GetValidInput(d2);

			char op = ' ';
			switch (choice) {
			case ADD:
				op = '+';
				result = calc.Add(d1, d2);
				break;
			case SUB:
				op = '-';
				result = calc.Substract(d1, d2);
				break;
			case MUL:
				op = '*';
				result = calc.Multiply(d1, d2);
				break;
			case DIV:
				op = '/';
				result = calc.Divide(d1, d2);
				break;
			case POWER:
				op = '^';
				result = calc.Power(static_cast<int>(d1), static_cast<int>(d2));
				break;
			}
			cout << d1 << " " << op << d2 << " = " << result << endl;
		}

	}

	return 0;
}