#include <iostream>

using std::cout; using std::endl; using std::cin;

int main()
{
	int n, sum, average;

	while (true) {
		cout << "���� �Է��ϼ��� : ";
		cin >> sum;
		cout << "�ο����� �Է��ϼ��� : ";
		cin >> n;

		try {
			if (n <= 0)
				throw n;
			else
				average = sum / n;
		}
		catch (int x) {
			cout << "���� �߻� : " << x << "���� ���� �� ����" << endl;
			average = 0;
			cout << endl;
			continue;
		}
		cout << "��� = " << average << endl << endl;		// ��� ���
	}

	return 0;
}