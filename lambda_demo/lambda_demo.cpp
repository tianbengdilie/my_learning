#include <iostream>
#include <functional>
using namespace std;

int main() {
	auto term = [](int a)->int {
		return a * a;
	};

	auto next = [](int a)->int {
		return ++a;
	};

	function<int(int, int)> sum = [term, next, &sum](int a, int b)mutable ->int {
		if (a > b)
			return 0;
		else
			return term(a) + sum(next(a), b);
	};

	std::cout << sum(1, 3) << std::endl;
	return 0;
}