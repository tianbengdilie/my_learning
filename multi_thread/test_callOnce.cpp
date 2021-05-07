#include "header.h"

#include <mutex>
#include <condition_variable>
#include <iostream>
using namespace std;

static void callonceFunc() {
	cout << "here should be called once" << endl;
}

static void helper() {
	static once_flag flag;
	call_once(flag, callonceFunc);
}

void testCallOnce() {
	for (int i = 0; i < 5; ++i) {
		helper();
	}
}