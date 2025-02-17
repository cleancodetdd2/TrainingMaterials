#include <iostream>

using std::cin; using std::cout; using std::endl;

class Army
{
public:
	virtual void Run() {
		cout << endl;
		cout << this->_Speed << "�� �ӵ��� ";
	}

	virtual void Attack() {
		cout << endl;
		cout << "���ݷ� - " << this->_Attack << "���� ";
	}

	virtual ~Army() { cout << "Army �θ� �Ҹ��� ȣ�� " << endl; }

protected:
	int _HP;		// ü��
	int _MP;		// ����
	int _Speed;		// �ӵ�
	int _Attack;	// ���ݷ�
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

	void Run() override {		// �θ� Ŭ������ �Լ��� ������
		Army::Run();
		cout << "Healer ��  Run() : " << this->_Speed;
	}

	void Attack() override {
		Army::Attack();
		cout << "Healer �� ����!";
	}

	~Healer() { cout << "Healer �ڽ� �Ҹ��� ȣ��" << endl; }
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

	void Run() override {		// �θ� Ŭ������ �Լ��� ������
		Army::Run();
		cout << "Giant ��  Run() : " << this->_Speed;
	}

	void Attack() override {
		Army::Attack();
		cout << "Giant �� ����!";
	}

	~Giant() { cout << "Giant �ڽ� �Ҹ��� ȣ��" << endl; }
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

	void Run() override {		// �θ� Ŭ������ �Լ��� ������
		Army::Run();
		cout << "Barbarian ��  Run() : " << this->_Speed;
	}

	void Attack() override {
		Army::Attack();
		cout << "Barbarian �� ����!";
	}

	~Barbarian() { cout << "Barbarian �ڽ� �Ҹ��� ȣ��" << endl; }
};

//void PrintAll(Army* (arrArmys)[], int size)			// �迭
void PrintAll(Army** arrArmys, int size) {				// ������ �迭
	for (int i = 0; i < 10; i++) {
		if (nullptr != arrArmys[i])						// ��ü�� �����Ǿ����� Ȯ��
			arrArmys[i]->Run();
	}

	cout << endl;

	for (int i = 0; i < 10; i++) {
		if (nullptr != arrArmys[i])						// ��ü�� �����Ǿ����� Ȯ��
			arrArmys[i]->Attack();
	}

	cout << endl<< endl;
	
}

int main()
{
	//Army* arrArmys[10]{};		//�迭
	Army** arrArmys = new Army * [10] {};		// ������ �迭

	arrArmys[0] = new Barbarian();				// ��ü ����
	arrArmys[1] = new Giant();					// ��ü ����
	arrArmys[2] = new Healer();					// ��ü ����	

	PrintAll(arrArmys, 10);

	//��ü ����
	for (int i = 0; i < 10; i++) {
		if (nullptr != arrArmys[i]) {
			delete arrArmys[i];			// ��ü ����
			arrArmys[i] = nullptr;		// ������ ��ü�� nullptr �ʱ�ȭ
		}
	}

	delete[] arrArmys;		// �޸� ���� (��ü �迭�� �ƴ϶� ������ �迭�� �����ϴ� ��)
	arrArmys = nullptr;		// ������ ��ü�� nullptr �ʱ�ȭ

	if (nullptr == arrArmys)
		cout << "\n\n ���� �Ǿ����ϴ�." << endl;
	else 
		cout << "\n\n ���� ���� �ʾҽ��ϴ�." << endl;

	return 0;
}