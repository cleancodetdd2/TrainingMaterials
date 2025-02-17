#include <iostream>

using std::cin; using std::cout; using std::endl;

class Army
{
public:
	virtual void Run() {
		cout << endl;
		cout << this->_Speed << "의 속도로 ";
	}

	virtual void Attack() {
		cout << endl;
		cout << "공격력 - " << this->_Attack << "으로 ";
	}

	virtual ~Army() { cout << "Army 부모 소멸자 호출 " << endl; }

protected:
	int _HP;		// 체력
	int _MP;		// 마력
	int _Speed;		// 속도
	int _Attack;	// 공격력
};

class Healer : public Army
{
public:
	Healer() {
		this->_HP = 50;
		this->_MP = 100;
		this->_Speed = 200;
		this->_Attack = 10;
	}

	void Run() override {		// 부모 클래스의 함수를 재정의
		Army::Run();
		cout << "Healer 의  Run() : " << this->_Speed;
	}

	void Attack() override {
		Army::Attack();
		cout << "Healer 의 공격!";
	}

	~Healer() { cout << "Healer 자식 소멸자 호출" << endl; }
};

class Giant : public Army
{
public:
	Giant() {
		this->_HP = 200;
		this->_MP = 0;
		this->_Speed = 10;
		this->_Attack = 200;
	}

	void Run() override {		// 부모 클래스의 함수를 재정의
		Army::Run();
		cout << "Giant 의  Run() : " << this->_Speed;
	}

	void Attack() override {
		Army::Attack();
		cout << "Giant 의 공격!";
	}

	~Giant() { cout << "Giant 자식 소멸자 호출" << endl; }
};

class Barbarian : public Army
{
public:
	Barbarian() {
		this->_HP = 100;
		this->_MP = 0;
		this->_Speed = 100;
		this->_Attack = 100;
	}

	void Run() override {		// 부모 클래스의 함수를 재정의
		Army::Run();
		cout << "Barbarian 의  Run() : " << this->_Speed;
	}

	void Attack() override {
		Army::Attack();
		cout << "Barbarian 의 공격!";
	}

	~Barbarian() { cout << "Barbarian 자식 소멸자 호출" << endl; }
};

//void PrintAll(Army* (arrArmys)[], int size)			// 배열
void PrintAll(Army** arrArmys, int size) {				// 포인터 배열
	for (int i = 0; i < 10; i++) {
		if (nullptr != arrArmys[i])						// 객체가 생성되었는지 확인
			arrArmys[i]->Run();
	}

	cout << endl;

	for (int i = 0; i < 10; i++) {
		if (nullptr != arrArmys[i])						// 객체가 생성되었는지 확인
			arrArmys[i]->Attack();
	}

	cout << endl<< endl;
	
}

int main()
{
	//Army* arrArmys[10]{};		//배열
	Army** arrArmys = new Army * [10] {};		// 포인터 배열

	arrArmys[0] = new Barbarian();				// 객체 생성
	arrArmys[1] = new Giant();					// 객체 생성
	arrArmys[2] = new Healer();					// 객체 생성	

	PrintAll(arrArmys, 10);

	//객체 삭제
	for (int i = 0; i < 10; i++) {
		if (nullptr != arrArmys[i]) {
			delete arrArmys[i];			// 객체 삭제
			arrArmys[i] = nullptr;		// 삭제된 객체를 nullptr 초기화
		}
	}

	delete[] arrArmys;		// 메모리 해제 (객체 배열이 아니라 포인터 배열을 삭제하는 것)
	arrArmys = nullptr;		// 삭제된 객체를 nullptr 초기화

	if (nullptr == arrArmys)
		cout << "\n\n 삭제 되었습니다." << endl;
	else 
		cout << "\n\n 삭제 되지 않았습니다." << endl;

	return 0;
}