#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int num;
	cout << "�л� �� �Է� : ";
	cin >> num;

	//int score[num];  // �迭�� ���� �Ҵ��� �Ǿ� �� -- �����Ͻ� �޸� ũ�Ⱑ �����Ǿ� �� 
	int* score = new int[num]; //���� ��(run-time)�� �޸𸮸� �Ҵ�(���� �Ҵ�) => heap ���� 
	double total = 0;
	for (int i = 0; i < num; i++)
	{
		cout << i + 1 << "��° ���� �Է� : ";
		cin >> score[i];
		total += score[i];
	}

	cout << num << "�� �л��� ���� ����� " << total / num << "�Դϴ�.\n";

	delete[] score;  //���� �Ҵ�� �޸𸮴� �ݵ�� ���ŵž� �� 

	return 0;
}