#include <iostream>

using std::cin; using std::cout; using std::endl;

/*
	�Լ� ���ø��� �Լ��� ������ Ʋ��.
*/

template <typename T>		// ���ø� ���� (T�� Ÿ�� �Ķ����)
void swap(T& x, T& y)		// �Լ� ���ø� ����
{
	int temp = x;
	x = y;
	y = temp;
}

template <int N>			// ���ø� ���� (N�� �� �Ķ����)
int func(int(&nums)[N])		// �Լ� ���ø� ����
{
	return N;
}

// Ÿ�� �Ķ���Ϳ� �� �Ķ���͸� ���� �޴� ���ø�
template <int N, typename T>
int getSize(T(&nums)[N])
{
	return N;
}

int main()
{
	{
		int x = 10, y = 20;
		swap<int>(x, y);		// Ÿ�� ��� 
		cout << "x, y : " << x << ", " << y << endl;

		swap(x, y);				// Ÿ���� ������� �ʾƵ� Ÿ���� �߷е�
		cout << "x, y : " << x << ", " << y << endl;
		cout << endl;
	}

	{
		int nums[] = { 1, 2, 3 };

		cout << func<3>(nums) << endl;		// �� ���(���ø��� �Ķ���ͷ� int ��)
		cout << func(nums) << endl;		// �迭�� ����� �߷��� ���ؼ� ���Ҽ� ����

		for (int i = 0; i < 3; i++)
			cout << nums[i] << " ";
		cout << endl << endl;
	}

	{
		int nums[] = {4, 5, 6, 7, 8};
		cout << getSize<5>(nums) << endl;	//���� ��������� ���� (Ÿ�� �Ķ���ʹ� �߷�)
		cout << getSize<5, int>(nums) << endl;	//�� �Ķ���Ϳ� Ÿ�� �Ķ���͸� ��������� ����
		cout << getSize(nums) << endl;

		for (int i = 0; i < 5; i++)
			cout << nums[i] << " ";
		cout << endl << endl;

		char chars[] = { 'a', 'b', 'c' };
		cout << getSize(chars) << endl;
		cout << getSize<3>(chars) << endl;
		cout << getSize<3, char>(chars) << endl;

		for (int i = 0; i < 3; i++)
			cout << chars[i] << " ";
		cout << endl << endl;
	}

	return 0;
}