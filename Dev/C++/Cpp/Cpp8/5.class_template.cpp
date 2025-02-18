#include <iostream>
#include <vector>
#include <stdexcept>

using std::cin; using std::cout; using std::endl;

// 클래스 템플릿
template<typename T, int MaxSize = 100>
class Stack
{
private:
	std::vector<T> _items;
	int _maxSize;			// 최대 크기 변수

public:
	Stack();					//기본 생성자
	void push(const T& item);	//요소 추가
	void pop();					//요소 제거
	T& top();					//최상위 요소 반환
	bool empty() const;			//스택이 비어 있는지 확인
	size_t size() const;		//현재 스택 크기 반환
	void clear();				//스택을 비우는 함수 
	void printStack() const;	//스택 상태 출력 함수
};

// 기본 생성자
template<typename T, int MaxSize>
Stack<T, MaxSize>::Stack() : _maxSize(MaxSize) {}

// 요소 추가
template<typename T, int MaxSize>
void Stack<T, MaxSize>::push(const T& item)
{
	try
	{
		if (_items.size() < _maxSize)	// 현재 크기가 최대 크기보다 작으면
			_items.push_back(item);		// 요소를 벡터에 추가
		else
			throw std::out_of_range("스택 오버플로우 : 더이상 엘리먼트를 추가 불가함");
	}
	catch (const std::exception& e)
	{
		cout << "Exception : " << e.what() << endl;
	}
	printStack();
}

// 요소 제거 
template<typename T, int MaxSize>
void Stack<T, MaxSize>::pop()
{
	try
	{
		if (_items.empty())		// 스택이 비어 있는지 확인
			throw std::out_of_range("스택 언더플로우 : 제거할 요소가 없음");
		_items.pop_back();	// 마지막 요소 제거 
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	printStack();
}

//최상위 요소 반환(스택이 비어 있으면 예외 발생)
template<typename T, int MaxSize>
T& Stack<T, MaxSize>::top()
{
	if (_items.empty())
		throw std::out_of_range("스택이 비어 있음: 해당 top 요소가 없음");
	return _items.back();		// 마지막 요소 반환
}

//스택이 비어 있는지 확인
template<typename T, int MaxSize>
bool Stack<T, MaxSize>::empty() const
{
	return _items.empty();		// 벡터가 비어 있는지 확인
}

//현재 스택 크기 반환 함수
template<typename T, int MaxSize>
size_t Stack<T, MaxSize>::size() const
{
	return _items.size();		//현재 저장된 요소 개수 반환
}

// 스택을 비우는 함수
template<typename T, int MaxSize>
void Stack<T, MaxSize>::clear()
{
	_items.clear();		// 모든 요소 제거
	printStack();
}

// 스택 상태 출력 함수
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
	Stack<int, 3> s0;		// 정수형 스택, 최대 크기 3

	//요소 추가
	s0.push(1);
	s0.push(2);
	s0.push(4);			// 1 2 4

	// 최상위 요소 출력
	cout << "Top 요소 : " << s0.top() << " (Size: " << s0.size() << ")" << endl;	// 4

	// 최상위 요소 제거
	s0.pop();			// 1 2
	cout << "pop() 호출 후 Top 요소 : " << s0.top() << " (Size: " << s0.size() << ")" << endl; // 2


	cout << "\n------------------문자열 스택 생성----------------" << endl;
	Stack<std::string, 10> s1;		// 문자열 스택, 최대 크기 10
	s1.push("abcd");
	s1.push("1234");


	cout << "Top 요소 : " << s1.top() << " (Size: " << s1.size() << ")" << endl;
	s1.pop();
	cout << "pop() 호출 후 Top 요소 : " << s1.top() << " (Size: " << s1.size() << ")" << endl;

	s1.pop();		// 스택 비어 있음
	s1.pop();		// 예외 발생 예상

	s0.clear();

	return 0;
}