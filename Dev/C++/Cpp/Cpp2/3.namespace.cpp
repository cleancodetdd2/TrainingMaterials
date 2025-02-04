#include <iostream>


namespace A {
	void megait() {
		std::cout << "1. megait\n";
	}
}

namespace B {
	void megait() {
		std::cout << "2. megait\n";
	}
}

namespace C {
	void megait() {
		std::cout << "3. megait\n";
	}
}

using namespace C;

int main()
{
	//A::megait();			// :: 범위 지정 연산자
	//B::megait();
	megait();
	return 0;
}