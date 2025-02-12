#include <iostream>

using std::cin; using std::cout; using std::endl;

class MyClass
{
private:
	int size;
	int* data;

public:
	MyClass(int n) : size(n), data(new int[n]) {
		for (int i = 0; i < size; i++)
			data[i] = i;		// �迭 �ʱ�ȭ
		cout << "������ : " << size << "���� int �� �޸� �Ҵ�\n";
	}

	//���� ������ (���� ����)
	MyClass(const MyClass& other) : size(other.size), data(new int[other.size]) {
		for (int i = 0; i < size; i++)
			data[i] = other.data[i];

		cout << "���� ������ ȣ��(���� ���� ����)\n\n";
	}

	// ������ �����ε� (���� ����)
	MyClass& operator=(const MyClass& other) {
		if (this != &other) {
			delete[] data;

			// ���ο� �޸� �Ҵ� �� ���� 
			this->size = other.size;
			this->data = new int[size];
			for (int i = 0; i < size; i++)
				data[i] = other.data[i];

			cout << "�����ε��� ���� ������ ȣ��(���� ���� ����)\n";
 		}
		return *this;

	}

	~MyClass() {
		cout << "�Ҹ��� : " << data <<  "�޸� ����\n";
		delete[] data;
	}

	void printData() const
	{
		for (int i = 0; i < size; i++)
			cout << data[i] << " ";
		cout << endl;
		cout << "\n";
	}
};

int main()
{
	MyClass m1(5);
	m1.printData();

	MyClass m2(m1);		//���� ������ ȣ��
	m2.printData();

	MyClass m3(3);
	m3 = m1;
	m3.printData();

	return 0;
}