#include "asio_demo.h"

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include <memory>
using namespace std;

// 使用google 的 protobuf

// 这个的目的是使用asio，完成文件的传输
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using boost::asio::io_context;

string filepath1 = "./test_dir/论文.doc";

static size_t getFileSize(const string& filename) {
	ifstream ifs(filename);
	ifs.seekg(0, ios::end);
	return ifs.tellg();
}

void sendFile(io_context & ioc) {

	// 获得多个地址
	tcp::resolver resolver(ioc);
	tcp::resolver::results_type endpoints = resolver.resolve("localhost", "10114");

	tcp::socket socket(ioc);
	boost::asio::connect(socket, endpoints);

	char buffer[BUF_SIZE];

	auto hFile = fopen(filepath1.c_str(), "rb");

	while (!feof(hFile)) {
		size_t len = 0;
		len = fread(buffer, sizeof(char), BUF_SIZE, hFile);

		boost::asio::write(socket, boost::asio::buffer(buffer, len));
	}

	cout << "发送完毕" << endl;
}

void transferFile() {
	io_context ioc2;
	sendFile(ioc2);
}