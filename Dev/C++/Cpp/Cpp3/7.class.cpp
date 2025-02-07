#include <iostream>
using std::cin; using std::cout; using std::endl;

#define OP_COUNT 7		// 연산 종류 개수 정의

/*
	열거형(enum)
	- 연산 종류를 나타냄
	- 각 연산자는 1부터 시작함, 1씩 증가는 정수 값을 가짐 
*/
/*
	mutable
	- const 함수에서도 변경 가능하도록 mutable 적용
	- 일반적으로 const 함수내에서는 멤버 변수 변경이 불가능함 
	- mutable을 사용하면 const 함수 내에서도 해당 변수의 값을 변경할 수 있음
*/
enum eOperator {
	ADD = 1,
	SUB,
	MUL,
	DIV,
	POWER,			//거듭제공
	POWER_OF_TWO	//2의 거듭제공 
};

//계산기 클래스 정의 
class Calculator {					// const 함수로 선언하여 멤버변수 변경이 불가능함.
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
			cout << "오류 : 0으로 나눌 수 없습니다." << endl;
			return 0;
		}
		++mCount[DIV];
		return d1 / d2;
	}

	// 거듭제곱 연산 함수 (음수 지수 예외처리)
	std::int64_t Power(int x, int y) const {
		if (y < 0) {
			cout << "오류 : 음의 지수는 지원되지 않습니다." << endl;
			return 0;
		}
		++mCount[POWER];

		std::int64_t result = 1;
		for (int i = 0; i < y; i++)
			result *= x;

		return result;
	}

	// 2의 거듭제곱 연산 함수
	std::int64_t PowerOfTwo(int y) const {
		if (y < 0) {
			cout << "오류 : 음의 지수는 지원되지 않습니다." << endl;
			return 0;
		}
		++mCount[POWER_OF_TWO];
		return 1LL << y;
	}

	//연산 횟수를 출력하는 함수
	void ShowOperationCount() const {
		cout << "\n\n -- 연산 횟수 출력 --\n\n";
		cout << "덧셈: " << mCount[ADD] << "회\n";
		cout << "뺄셈: " << mCount[SUB] << "회\n";
		cout << "곱셈: " << mCount[MUL] << "회\n";
		cout << "나눗셈: " << mCount[DIV] << "회\n";
		cout << "거듭제곱: " << mCount[POWER] << "회\n";
		cout << "2의 거듭제곱: " << mCount[POWER_OF_TWO] << "회\n";
	}

private:	
	mutable int mCount[OP_COUNT] = { 0 };	// 연산 횟수를 저장하는 배열 
};

//입력 검증 함수 (유효한 숫자 입력을 받을때까지 반복)
void GetValidInput(double& num) {
	while (true) {
		cin >> num;
		if (cin.fail()) {	//입력 데이터의 형식이 맞지 않으면 오류 발생=> true반환(입력실패)
			cout << "잘못된 선택입니다. 다시 입력하세요." << endl;
			cin.clear();	// cin의 오류 상태를 초기화하여 다시 입력 받을 수 있게 함 
			cin.ignore(1000, ' '); // 입력 버퍼에서 최대 1000개 문자 또는 개행문자가 나올때까지 버퍼를 비움.
		}
		else {
			break;
		}
	}
}

int main()
{
	Calculator calc;		// Calculator 객체 생성

	while (true) {
		cout << "\n\n --- 계산기 프로그램 ---\n";
		cout << "1. 덧셈	2. 뺄셈	  3. 곱셈   4. 나누기   5. 거듭제곱    6. 2의 거듭제곱   0. 종료\n";
		cout << "메뉴 선택 : ";

		int choice;
		cin >> choice;

		//잘못된 입력 처리
		if (cin.fail() || choice < 0 || choice > 6) {
			cout << "잘못된 선택입니다. 다시 입력하세요." << endl;
			cin.clear();
			cin.ignore(1000, ' '); // 입력 버퍼를 비워 다음 입력 오류 방지 
			continue;
		}

		//프로그램 종료 
		if(choice == 0) {
			calc.ShowOperationCount();
			return 0;
		}

		double d1, d2, result = 0;
		if (choice == POWER_OF_TWO) {
			cout << "지수 입력 : ";
			GetValidInput(d2);

			result = calc.PowerOfTwo(static_cast<int>(d2));		//2의 거듭제곱 계산(소수점 버림)
			cout << "2^ " << static_cast<int>(d2) << " = " << result << endl;
		} 
		else {
			cout << "두 숫자 입력 : ";
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