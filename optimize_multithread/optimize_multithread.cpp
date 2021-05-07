#include <pthread.h>
#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

void* foo(void* ptr)
{
	int* data = (int*)ptr;
	for (int i = 0; i < 10000000; i++) {
		*data += rand();
	}
	return nullptr;
}

int main()
{
	srand((unsigned int)time(NULL));
	int arr[9];
	pthread_t thd1, thd2;
	int *ptr1 = arr;
	int *ptr2 = arr + 8;
	auto start_time = high_resolution_clock::now();
	pthread_create(&thd1, NULL, foo, ptr1);
	pthread_create(&thd2, NULL, foo, ptr2);

	pthread_join(thd1, NULL);
	pthread_join(thd2, NULL);
	auto end_time = high_resolution_clock::now();
	cout << "Total: " << *ptr1 + *ptr2 << endl;

	cout << "Time elapsed: " << duration_cast<microseconds>(end_time -
		start_time).count() / 1000.f
		<< " ms" << endl;

	return 0;
}