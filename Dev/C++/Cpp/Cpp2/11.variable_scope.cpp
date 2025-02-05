#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int global = 1;			//��������

void func(int arg) {	//�Ű�����
	int x = 1;			//��������
	static int sta = 1;	//�������� = ��������(�ش��ϳ����� ���) + ��������(������ scope)

	global++;
	sta++;
	x++;

	cout << global << ", " << sta << ", " << x << endl;
}

void func2() {
	global = 100;
	//sta = 200;  //error
	cout << "global = " << global << endl;
}

int main()
{
	int a = 3;	//��������

	{
		int b = 7;		//��������
		int c = 9;		//��������
	}

	func(100);
	func(200);
	func(300);
	func2();
	cout << "global = " << global << endl;

	return 0;
}