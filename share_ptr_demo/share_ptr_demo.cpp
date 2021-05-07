// share_ptr_demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <memory>
#include <iostream>
#include <unordered_map>
#include <array>
using namespace std;

int main()
{
	std::unordered_map<std::string, std::string> m_ownTicketMap;
	m_ownTicketMap["000001"] = "1";
	m_ownTicketMap["000002"] = "1";
	m_ownTicketMap["000003"] = "1";
	m_ownTicketMap["000004"] = "1";
	auto itUnit = m_ownTicketMap.begin();

	std::shared_ptr<std::array<char, 7>> result(new std::array<char, 7>[m_ownTicketMap.size()]);

	for (int i = 0; i < m_ownTicketMap.size() && itUnit != m_ownTicketMap.end(); ++i, ++itUnit) {
		memset(result.get()[i].data(), 0, 7);
		memcpy(result.get()[i].data(), itUnit->first.data(), itUnit->first.size());
	}

	char** vec = (char**) result.get()[0].data();
	
	for (int i = 0; i < 4; ++i) {
		cout << vec[i] << endl;
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
