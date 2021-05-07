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

	// ��ȡ������������еĳ���
	cout << p.ByteSizeLong() << endl;
	p.PrintDebugString();

	// ���ɶ���Ķ���������
	string tmp;
	p.SerializeToString(&tmp);
	
	// �Ӷ����������л�ȡ����
	cout << "\n\n\n�����л���\n";
	Person p2;
	p2.ParseFromString(tmp);
	p2.PrintDebugString();
	cout << "size: " << p2.ByteSizeLong() << endl;

	// ��ȡָ������������
	cout << "phone_size: " << p2.phones_size() << endl;
	p2.phones(0).PrintDebugString();

	// ģ��ճ������
	cout << "\n\n\nճ�����⣺\n";
	p2.SerializeToString(&tmp);

	auto tmp2 = p2.SerializeAsString();
	tmp += tmp2.substr(0,10);

	Person p3;
	p3.ParseFromString(tmp);
	p3.PrintDebugString();
	cout << "size: " << p3.ByteSizeLong() << endl;

	// ʹ�ýض��ǿ��Խ��ճ���ģ��������������repeated���Ե�field���޷�����ˡ�
	// ��֮���ǻ��Ǵ���ճ������ġ�
	cout << endl;
	tmp = tmp.substr(0, p3.ByteSizeLong());
	p3.ParseFromString(tmp);
	p3.PrintDebugString();

	return 0;
}