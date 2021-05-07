#include "demo.pb.h"

#include <iostream>
#include <string>

using namespace std;

using demo::Person;
using demo::Person_PhoneNumber;

int main() {
	Person p;
	p.set_id(25);
	p.set_name("hello world");
	p.set_email("453@qq.com");

	auto phoneNumber = p.add_phones();
	phoneNumber->set_type(Person::PhoneType::Person_PhoneType_HOME);
	phoneNumber->set_number("13929392939");
	phoneNumber = p.add_phones();
	phoneNumber->set_type(Person::PhoneType::Person_PhoneType_HOME);
	phoneNumber->set_number("13929392939");

	// 获取对象二进制序列的长度
	cout << p.ByteSizeLong() << endl;
	p.PrintDebugString();

	// 生成对象的二进制序列
	string tmp;
	p.SerializeToString(&tmp);
	
	// 从二进制序列中获取对象
	cout << "\n\n\n反序列化：\n";
	Person p2;
	p2.ParseFromString(tmp);
	p2.PrintDebugString();
	cout << "size: " << p2.ByteSizeLong() << endl;

	// 获取指定索引的属性
	cout << "phone_size: " << p2.phones_size() << endl;
	p2.phones(0).PrintDebugString();

	// 模拟粘包问题
	cout << "\n\n\n粘包问题：\n";
	p2.SerializeToString(&tmp);

	auto tmp2 = p2.SerializeAsString();
	tmp += tmp2.substr(0,10);

	Person p3;
	p3.ParseFromString(tmp);
	p3.PrintDebugString();
	cout << "size: " << p3.ByteSizeLong() << endl;

	// 使用截断是可以解决粘包的，但是如果遇到了repeated属性的field就无法解决了。
	// 总之就是还是存在粘包问题的。
	cout << endl;
	tmp = tmp.substr(0, p3.ByteSizeLong());
	p3.ParseFromString(tmp);
	p3.PrintDebugString();

	return 0;
}