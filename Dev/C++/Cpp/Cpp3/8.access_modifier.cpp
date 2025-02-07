/*
	접근 지정자(Access Modifier)
		- public : 공개, 어디서든 접근 가능한 멤버
		- private : 비공개, 클래스 내에서만 접근 가능한 멤버 
		- 접근 제어자 생략시 private이 됨.
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
			fire();		//미사일 발사
		else
			error();	//경고 메시지 출력 
	}
private:
	const string pw;		//비밀번호
	void fire() {
		cout << "미사일을 발사합니다!!!\n";
	}
	void error() {
		cout << "비밀번호 오류!!\n";
	}
};

int main()
{
	//인스턴스 생성
	Missile mis("2527");
	//사용자에게 비밀번호 입력받기
	string inputPw;
	cout << "비밀번호 입력 : ";
	cin >> inputPw;

	mis.pwCheck(inputPw);

	return 0;
}