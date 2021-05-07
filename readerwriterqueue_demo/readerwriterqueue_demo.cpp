#define  _CRT_SECURE_NO_WARNINGS

#include <readerwriterqueue/readerwriterqueue.h>

#include <thread>
#include <iostream>
#include <string>
using namespace std;

struct Order {
	char id[7];
	double price;
	int volume;

	Order() = default;
	Order& operator=(const Order& o) {
		//cout << "copy asignment" << endl;
		memcpy(this, &o, sizeof(o));
		return *this;
	}
	Order(const Order& o) {
		//cout << "copy constructor" << endl;
		memcpy(this, &o, sizeof(o));
	}
};

moodycamel::BlockingReaderWriterQueue<Order> bqueue(50);  // 这个会产生阻塞

void bconsumer() {
	Order o;
	while (true) {
		bqueue.wait_dequeue(o);
		printf("%s %lf %d\n", o.id, o.price, o.volume);
	}
}

void bproducer() {
	Order o;
	strcpy(o.id, "000001");
	o.price = 1.2;
	for (int i = 0; i < 100; ++i) {
		o.volume = i * 100;
		if (bqueue.try_emplace(o) == false) {
			cout << "lack of memory" << endl;
			bqueue.emplace(o);
		}
		this_thread::sleep_for(chrono::milliseconds(1));
	}
}

moodycamel::ReaderWriterQueue<Order> queue(2);  //
void consumer() {
	Order o;
	while (true) {
		while (queue.try_dequeue(o) == false);
		printf("%s %lf %d\n", o.id, o.price, o.volume);
	}
}
void producer() {
	Order o;
	strcpy(o.id, "000001");
	o.price = 1.2;
	for (int i = 0; i < 100; ++i) {
		o.volume = i * 100;
		if (queue.try_emplace(o) == false) {
			cout << "lack of memory" << endl;
			queue.emplace(o);
		}
		this_thread::sleep_for(chrono::milliseconds(1));
	}
}

int main() {
	{
		thread th1(producer);
		thread th2(consumer);

		th2.join();
	}

	{
		thread th1(bproducer);
		thread th2(bconsumer);

		th2.join();
	}
}