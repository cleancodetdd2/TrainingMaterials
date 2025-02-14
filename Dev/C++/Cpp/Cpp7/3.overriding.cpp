#include <iostream>

using std::cin; using std::cout; using std::endl;

// �θ� Ŭ���� (����)
class Animal {
public:
	virtual void Walk() { cout << "[�θ� Ŭ����] �ȴ´�.\n"; }
	virtual void Speak() { cout << "[�θ� Ŭ����] �Ҹ��� ����.\n"; }
	virtual ~Animal() = default;		//���� �Ҹ��� �߰�
};

// �ڽ� Ŭ����
class Dog : public Animal {
public:
	void Speak() override { cout << "[�ڽ� Ŭ����] �۸�!! \n"; }
};

// �ڽ� Ŭ����
class Cat : public Animal {
public:
	void Speak() override { cout << "[�ڽ� Ŭ����] �߿�!! \n"; }
};

// �ڽ� Ŭ����
class Fox : public Animal {
public:
	void Speak() override { cout << "[�ڽ� Ŭ����] �߾�!! \n"; }
};

// �ڽ� Ŭ����
class Duck : public Animal {
public:
	void Walk() override { cout << "[�ڽ� Ŭ����] �ι߷� �ȴ´�.\n"; }
	void Speak() override { cout << "[�ڽ� Ŭ����] �в�!! \n"; }
};

Animal* CreateAnimal(int choice) {
	switch (choice) {
	case 1: return new Dog();
	case 2: return new Cat();
	case 3: return new Fox();
	case 4: return new Duck();
	default: return nullptr;
	}
}

int main()
{
	while (true) {
		//system("cls");	//�ܼ� ȭ�� �����
		cout << "\n\t\t--- ������ ����---\n\n";
		cout << "1.Dog   2.Cat  3.fox  4.Duck   0.����\n";
		cout << "���� : ";

		int choice;
		cin >> choice;

		if (choice == 0) break;

		Animal* animal = CreateAnimal(choice);

		if (animal) {
			animal->Speak();
			animal->Walk();
			delete animal;
		}
		else {
			cout << "�߸��� �����Դϴ�.\n";
		}

		cout << "\n\n";
	}

	return 0;
}