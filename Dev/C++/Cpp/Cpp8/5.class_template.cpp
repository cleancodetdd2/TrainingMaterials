#include <iostream>
#include <vector>
#include <stdexcept>

using std::cin; using std::cout; using std::endl;

// Ŭ���� ���ø�
template<typename T, int MaxSize = 100>
class Stack
{
private:
	std::vector<T> _items;
	int _maxSize;			// �ִ� ũ�� ����

public:
	Stack();					//�⺻ ������
	void push(const T& item);	//��� �߰�
	void pop();					//��� ����
	T& top();					//�ֻ��� ��� ��ȯ
	bool empty() const;			//������ ��� �ִ��� Ȯ��
	size_t size() const;		//���� ���� ũ�� ��ȯ
	void clear();				//������ ���� �Լ� 
	void printStack() const;	//���� ���� ��� �Լ�
};

// �⺻ ������
template<typename T, int MaxSize>
Stack<T, MaxSize>::Stack() : _maxSize(MaxSize) {}

// ��� �߰�
template<typename T, int MaxSize>
void Stack<T, MaxSize>::push(const T& item)
{
	try
	{
		if (_items.size() < _maxSize)	// ���� ũ�Ⱑ �ִ� ũ�⺸�� ������
			_items.push_back(item);		// ��Ҹ� ���Ϳ� �߰�
		else
			throw std::out_of_range("���� �����÷ο� : ���̻� ������Ʈ�� �߰� �Ұ���");
	}
	catch (const std::exception& e)
	{
		cout << "Exception : " << e.what() << endl;
	}
	printStack();
}

// ��� ���� 
template<typename T, int MaxSize>
void Stack<T, MaxSize>::pop()
{
	try
	{
		if (_items.empty())		// ������ ��� �ִ��� Ȯ��
			throw std::out_of_range("���� ����÷ο� : ������ ��Ұ� ����");
		_items.pop_back();	// ������ ��� ���� 
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	printStack();
}

//�ֻ��� ��� ��ȯ(������ ��� ������ ���� �߻�)
template<typename T, int MaxSize>
T& Stack<T, MaxSize>::top()
{
	if (_items.empty())
		throw std::out_of_range("������ ��� ����: �ش� top ��Ұ� ����");
	return _items.back();		// ������ ��� ��ȯ
}

//������ ��� �ִ��� Ȯ��
template<typename T, int MaxSize>
bool Stack<T, MaxSize>::empty() const
{
	return _items.empty();		// ���Ͱ� ��� �ִ��� Ȯ��
}

//���� ���� ũ�� ��ȯ �Լ�
template<typename T, int MaxSize>
size_t Stack<T, MaxSize>::size() const
{
	return _items.size();		//���� ����� ��� ���� ��ȯ
}

// ������ ���� �Լ�
template<typename T, int MaxSize>
void Stack<T, MaxSize>::clear()
{
	_items.clear();		// ��� ��� ����
	printStack();
}

// ���� ���� ��� �Լ�
template<typename T, int MaxSize>
void Stack<T, MaxSize>::printStack() const
{
	cout << "Stack state (size: " << _items.size() << "): ";
	for (const auto& item : _items)
		cout << item << " ";
	cout << endl << endl;
}

int main()
{
	Stack<int, 3> s0;		// ������ ����, �ִ� ũ�� 3

	//��� �߰�
	s0.push(1);
	s0.push(2);
	s0.push(4);			// 1 2 4

	// �ֻ��� ��� ���
	cout << "Top ��� : " << s0.top() << " (Size: " << s0.size() << ")" << endl;	// 4

	// �ֻ��� ��� ����
	s0.pop();			// 1 2
	cout << "pop() ȣ�� �� Top ��� : " << s0.top() << " (Size: " << s0.size() << ")" << endl; // 2


	cout << "\n------------------���ڿ� ���� ����----------------" << endl;
	Stack<std::string, 10> s1;		// ���ڿ� ����, �ִ� ũ�� 10
	s1.push("abcd");
	s1.push("1234");


	cout << "Top ��� : " << s1.top() << " (Size: " << s1.size() << ")" << endl;
	s1.pop();
	cout << "pop() ȣ�� �� Top ��� : " << s1.top() << " (Size: " << s1.size() << ")" << endl;

	s1.pop();		// ���� ��� ����
	s1.pop();		// ���� �߻� ����

	s0.clear();

	return 0;
}