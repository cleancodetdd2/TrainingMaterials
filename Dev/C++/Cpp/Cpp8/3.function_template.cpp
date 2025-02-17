#include <iostream>

using std::cin; using std::cout; using std::endl;

/*
	함수 템플릿은 함수를 만들어내는 틀임.
*/

template <typename T>		// 템플릿 선언 (T는 타입 파라미터)
void swap(T& x, T& y)		// 함수 템플릿 정의
{
	int temp = x;
	x = y;
	y = temp;
}

template <int N>			// 템플릿 선언 (N은 값 파라미터)
int func(int(&nums)[N])		// 함수 템플릿 정의
{
	return N;
}

// 타입 파라미터와 값 파라미터를 같이 받는 템플릿
template <int N, typename T>
int getSize(T(&nums)[N])
{
	return N;
}

int main()
{
	{
		int x = 10, y = 20;
		swap<int>(x, y);		// 타입 명시 
		cout << "x, y : " << x << ", " << y << endl;

		swap(x, y);				// 타입을 명시하지 않아도 타입이 추론됨
		cout << "x, y : " << x << ", " << y << endl;
		cout << endl;
	}

	{
		int nums[] = { 1, 2, 3 };

		cout << func<3>(nums) << endl;		// 값 명시(템플릿의 파라미터로 int 값)
		cout << func(nums) << endl;		// 배열의 사이즈를 추론을 통해서 구할수 있음

		for (int i = 0; i < 3; i++)
			cout << nums[i] << " ";
		cout << endl << endl;
	}

	{
		int nums[] = {4, 5, 6, 7, 8};
		cout << getSize<5>(nums) << endl;	//값을 명시적으로 지정 (타입 파라미터는 추론)
		cout << getSize<5, int>(nums) << endl;	//값 파라미터와 타입 파라미터를 명시적으로 지정
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