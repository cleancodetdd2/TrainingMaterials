#include <iostream>

int main()
{
	std::cout << "�� �� �Է�(���� ����) : ";
	int n1, n2;
	std::cin >> n1 >> n2;
	std::cout << "�Է� ���� ������ " << n1 << ", " << n2 << "�Դϴ�.\n";

	double avg;
	avg = (n1 + n2) / 2.0;
	std::cout << "���� ����� " << avg << "�Դϴ�.\n";
	std::cout << std::endl << std::endl;  //endline

	char ch;
	std::cout << "���� �Է� : ";
	std::cin >> ch;

	std::cout << "���� : " << ch << ", �ƽ�Ű �ڵ� : " << (int)ch << std::endl;

	if (ch >= 'A' && ch <= 'Z')	//�빮�ڶ��
		std::cout << ch << "==>" << (char)(ch + 32) << std::endl;
	else if (ch >= 'a' && ch <= 'z')		//�ҹ��ڶ��
		std::cout << ch << "==>" << (char)(ch - 32) << std::endl;

	return 0;
}