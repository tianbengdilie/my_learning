#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <picojson/picojson.h>

const char* const str_json = "{"
"	\"key1\": \"value1\",  "
"	\"key2\" : \"value2\", "
"	\"array\" : [		   "
"		1,2,3,4,5	   "
"	]				   "
"}";

// notice
// picojson only have one kind of numeric, that is double, no integrate

// output
// (array:[1, 2, 3, 4, 5])
// (key1:"value1")
// (key2:"value2")
// 1, 2, 3, 4, 5,
// { "array":[1,2,3,4,5],"key1" : "value1","key2" : "value2" }

void createNewElement() {
	map<string, map<string, int>> m;

	picojson::object root;
	for (const auto& i : m) {
		picojson::object account;
		for (const auto& j : i.second) {
			account[j.first] = picojson::value((double)j.second);
		}
		cout << endl << picojson::value(account).serialize() << endl;
		root[i.first] = picojson::value(account);
	}
}

void iterElement() {
	picojson::value root;

	// load from string
	string err = picojson::parse(root, str_json);

	// iter obj
	picojson::object obj = root.get<picojson::object>();
	for (picojson::value::object::iterator i = obj.begin(); i != obj.end(); ++i) {
		printf("(%s:%s)\n", i->first.data(), i->second.serialize().data());
	}

	// iter arr
	picojson::array arr = root.get("array").get<picojson::array>();
	for (auto i = arr.begin(); i != arr.end(); ++i) {
		printf("%s, ", i->serialize().data());
	}

	// serialize json
	cout << endl << root.serialize() << endl;
}

void createArrayElement() {
	picojson::array a;
	a.emplace_back("11");
	cout << picojson::value(a).serialize() << endl;
}

int main() {

	createArrayElement();

	return 0;
}