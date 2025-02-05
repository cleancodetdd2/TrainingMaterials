#include <iostream>
#define DEFAULT_INT_VALUE -1	
#define DEFAULT_DOUBLE_VALUE -1.0

using std::cout; using std::cin; using std::endl;

// �Լ� �����ε� : �����Ϳ� ������ �̿��� �Է� �Լ�
void input(int* p1, double *p2);		//call by address (������ ���)
void input(int& r1, double& r2);		//call by reference (���� ���)

void input(int* p1, double* p2)
{
	if (p1 == nullptr || p2 == nullptr) 
	{	// nullptr �˻�
		cout << "[������ ���] nullptr�� ���޵�. �⺻���� ������\n";
		return;
	}

	if (p1 == nullptr) {
		cout << "[������ ���] nullptr�� ���޵�. �⺻���� ������\n";
	} 
	else {
		cout << "[������ ���] ���� �Է� : ";
		cin >> *p1;
	}

	if (p2 == nullptr) {
		cout << "[������ ���] nullptr�� ���޵�. �⺻���� ������\n";
	}
	else {
		cout << "[������ ���] �Ǽ� �Է� : ";
		cin >> *p2;
	}

	cout << "�����͸� �̿��ؼ� �Է�(Call by Address)\n";

}

void input(int& r1, double& r2)
{
	cout << "[���� ���] ���� �Է� : ";
	cin >> r1;		// ������ �̿��Ͽ� ���� ���� �� �Ҵ�
	cout << "[���� ���] �Ǽ� �Է� : ";
	cin >> r2;		// ������ �̿��Ͽ� ���� ���� �� �Ҵ�
	cout << "���۷����� �̿��ؼ� �Է� (Call by Reference)";
}

int main()
{
	int value1 = DEFAULT_INT_VALUE, value2 = DEFAULT_INT_VALUE;
	double data1 = DEFAULT_DOUBLE_VALUE, data2 = DEFAULT_DOUBLE_VALUE;

	cout << "\n---- ������ ���(nullptr����) �׽�Ʈ ----\n";
	input(nullptr, nullptr);	

	value1 = DEFAULT_INT_VALUE;		//�⺻�� ����
	data1 = DEFAULT_DOUBLE_VALUE;	//�⺻�� ����
	cout << "[�⺻�� ����] value1 = " << value1 << ", data1 = " << data1 << "(�⺻�� �����)\n";
 
	cout << "\n -- ������ ��� �Է� �׽�Ʈ , value1--\n" << value1 << ", data1 = " << data1 << endl;
	input(&value1, &data1);
	cout << "[���� ��] value1 = " << value1 << ", data1 = " << data1 << endl;

	cout << "\n -- ���� ��� �Է� �׽�Ʈ, value2 --\n" << value2 << ", data2 = " << data2 << endl;
	input(value2, data2);
	cout << "[���� ��] value2 = " << value2 << ", data2 = " << data2 << endl;

	return 0;
}