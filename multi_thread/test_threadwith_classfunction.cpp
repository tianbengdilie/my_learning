#include "header.h"

class Foo {
public:
	void bar(int v) {
		for (int i = 0; i < v; ++i) {
			printf("%d\n", this->value++);

			this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
	
	int value = 1;
};

void testThreadWithClassFunction() {
	vector<thread> ths;
	Foo f;

	for (int i = 0; i < 3; ++i) {
		ths.emplace_back(&Foo::bar, &f, 3);
		ths.emplace_back(&Foo::bar, std::ref(f), 3);
	}

	for (auto& th : ths) th.join();
}