#include <thread>
#include <iostream>
#include <vector>
using namespace std;

#include <concurrentqueue/concurrentqueue.h>

moodycamel::ConcurrentQueue<int> q;

void Producer() {
	for (int i = 0; ; i++)
		q.enqueue(i);
}

void Consumer() {
	vector<int> cands(5);
	while (true) {
		q.try_dequeue_bulk(cands.begin(), 5);
		for(const auto c : cands)
		printf("%d ", c);
	}
}

int main() {
	thread p(Producer);
	thread p2(Consumer);
	thread d(Consumer);
	thread r(Consumer);
	thread g(Consumer);

	p.join();
}