#include <iostream>
#include <string>
#include <vector>	//C++ STL���� �����ϴ� ���� �迭 ���

using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

class Circle
{
private:
	string name;		// ����, ����, ����..
	string flavor;		// ��(����, ����, ġ��..)
	double radius;		// ũ��

public:
	Circle(string _name, string _flavor, double _radius)
		: name(_name), flavor(_flavor), radius(_radius) {
		if (radius <= 0)	//�������� 0 ������ ��� ���� �߻�
			throw std::invalid_argument("�������� 0���� Ŀ�� �մϴ�.");
		cout << name << " ��ü ���� �Ϸ�!\n";
	}
	//���� ��� �Լ�
	double getArea() const {
		return 3.141592 * radius * radius;
	}
	//��ü ���� ����ϴ� �Լ�
	void show() const {
		cout << "�̸� : " << name << ", �� : " << flavor << ", ���� : " << getArea() << endl;
	}

};



int main()
{
	// vector�� ����Ͽ� Circle ��ü �����͸� �������� ���� 
	vector<Circle*> circles;

	cout << "�� ���� Circle ��ü�� �����Ͻðڽ��ϱ�? ";
	int count;
	cin >> count;			//������ Circle ���� �Է� �ޱ� 

	for (int i = 0; i < count; i++)
	{
		string name, flavor;
		double radius;
		 
		//����ڷκ��� ��ü �Ӽ� �Է¹ޱ�
		cout << "�̸� : ";
		cin >> name;
		cout << "�� : ";
		cin >> flavor;
		cout << "������ : ";
		cin >> radius;

		try
		{
			// ���� �Ҵ��� ���� Circle ��ü ����
			Circle* newCircle = new Circle(name, flavor, radius);

			// ������ ��ü�� �����͸� ���Ϳ� ���� (�ڵ����� ũ�Ⱑ �þ)
			circles.push_back(newCircle);
		}
		catch (const std::exception& e)
		{
			//���� �߻� �� �޽��� ���
			cout << "���� �߻� : " << e.what() << endl;
		}
	}

	cout << "\n ������ Circle ����: \n";
	for (const auto& circle : circles)		// ������ ��� ��Ҹ� �����Ͽ� ���
		circle->show();

	for (auto& circle : circles)	// ���� �Ҵ�� ��ü�� �ݵ�� �����ؾ� �޸� ���� �����Ҽ� ����
		delete circle;		// new�� ������ ��ü �޸� ����

	circles.clear();		// �޸� ���� �� �߰����� ���� ��ġ 

	return 0;
}