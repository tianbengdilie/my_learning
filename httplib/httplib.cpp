// httplib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <httplib.h>
#include <iostream>

using namespace std;

int main(void)
{
	httplib::Client cli("117.114.227.39", 20088);

	httplib::Headers headers;
	headers.insert({ "Content-Type", "multipart/form-data; boundary=<calculated when request is sent>" });
	headers.insert({ "Cookie", "uname=wht; accessToken=47504398c296870a3bba124386f9147ad8be71de" });

	httplib::MultipartFormDataItems form{
		{"windCode", "000001.sz","", ""},
		{"date", "20201111","", ""},

	};

	auto re = cli.Post("/api/minute_history.php", headers, form);
	if (re->status == 200) {
		cout << re->body << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
