#define _CRT_SECURE_NO_WARNINGS
#include <csv.h>

#include <string>
#include <fstream>
using namespace std;

int main() {

	io::CSVReader<3> in("demo.csv");
	in.read_header(io::ignore_extra_column, "first", "second", "third");
	string first, second, third;

	while (in.read_row(first, second, third)) {
		printf("%s,%s,%s\n", first.data(), second.data(), third.data());
	}

	return 0;
}