#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

// ���ǰһ������
string getPreDate() {
	time_t n = time(nullptr) - 24 * 60 * 60;

	tm * ltm = localtime(&n);
	char buff[64];

	sprintf(buff, "%04d%02d%02d", ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday);

	return buff;
}

int main() {
	cout << getPreDate();
}
