#include <iostream>

using std::cin; using std::cout; using std::endl;

// 부모 클래스 (동물)
class Animal {
public:
	virtual void Walk() { cout << "[부모 클래스] 걷는다.\n"; }
	virtual void Speak() { cout << "[부모 클래스] 소리를 낸다.\n"; }
	virtual ~Animal() = default;		//가상 소멸자 추가
};

// 자식 클래스
class Dog : public Animal {
public:
	void Speak() override { cout << "[자식 클래스] 멍멍!! \n"; }
};

// 자식 클래스
class Cat : public Animal {
public:
	void Speak() override { cout << "[자식 클래스] 야옹!! \n"; }
};

// 자식 클래스
class Fox : public Animal {
public:
	void Speak() override { cout << "[자식 클래스] 야약!! \n"; }
};

// 자식 클래스
class Duck : public Animal {
public:
	void Walk() override { cout << "[자식 클래스] 두발로 걷는다.\n"; }
	void Speak() override { cout << "[자식 클래스] 꽥꽥!! \n"; }
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
		//system("cls");	//콘솔 화면 지우기
		cout << "\n\t\t--- 지구의 동물---\n\n";
		cout << "1.Dog   2.Cat  3.fox  4.Duck   0.종료\n";
		cout << "선택 : ";

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
			cout << "잘못된 선택입니다.\n";
		}

		cout << "\n\n";
	}

	return 0;
}