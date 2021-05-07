#include "asio_demo.h"

#include <array>
#include <iostream>

#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;


void Session(tcp::socket socket) {
	try {
		while (true) {
			array<char, BUF_SIZE> data;

			boost::system::error_code ec;
			size_t len = socket.read_some(boost::asio::buffer(data), ec);

			if (ec == boost::asio::error::eof) {
				cout << "client 正常退出连接" << endl;
			}
			else if (ec) {
				throw boost::system::system_error(ec);
			}

			boost::asio::write(socket, boost::asio::buffer(data, len));
		}
	}
	catch (const std::exception& e) {
		cerr << "exception: " << e.what() << endl;
	}
}

void startSyncTcpEchoServer() {

	boost::asio::io_context ioc;

	tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), port));

	try {
		while (true) {
			Session(acceptor.accept());
		}
	}
	catch (const std::exception& e) {
		cerr << "exception: " << e.what() << endl;
	}
}