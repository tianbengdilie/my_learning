#include <map>
#include <iostream>
using namespace std;

int main() {
	multimap<int, int> m;
	m.insert(make_pair(1, 20));
	m.insert(make_pair(1, 21));
	m.insert(make_pair(1, 22));
	for (const auto& p : m)
		printf("%d, %d\n", p.first, p.second);
}