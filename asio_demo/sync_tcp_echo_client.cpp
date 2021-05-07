#include "asio_demo.h"

#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

void startSyncTcpEchoClient() {
	boost::asio::io_context ioc;

	// 获得多个地址
	tcp::resolver resolver(ioc);
	tcp::resolver::results_type endpoints = resolver.resolve(host_ip, std::to_string(port));

	tcp::socket socket(ioc);
	boost::asio::connect(socket, endpoints);

	while (true) {

		char send[BUF_SIZE];
		size_t len = 0;
		do {
			std::cout << "input: ";
			std::cin.getline(send, BUF_SIZE);
			len = strlen(send);
			send[len] = '\n';
		} while (len == 0);

		boost::asio::write(socket, boost::asio::buffer(send, ++len));

		// 推荐使用read_some方式
		std::size_t total_reply_length = 0;;
		while (true) {
			std::array<char, BUF_SIZE> reply;
			std::size_t reply_length = socket.read_some(boost::asio::buffer(reply, BUF_SIZE));

			std::cout.write(reply.data(), reply_length);

			total_reply_length += reply_length;
			if (total_reply_length >= len) {
				break;
			}
		}

		//char receive[BUF_SIZE];
		//// 阻塞，知道buffer被全部填满
		//size_t len2 = boost::asio::read(socket, boost::asio::buffer(receive, len));
		//std::cout.write(receive, len2);
	}
}