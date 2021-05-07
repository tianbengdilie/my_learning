#include "asio_demo.h"

#include <boost/asio.hpp>

#include <string>
#include <iostream>

using std::string;
using boost::asio::ip::tcp;
using boost::system::error_code;


class Client {
public:
	Client(boost::asio::io_context & ioc, const std::string & host, const std::string& port)
		:socket_(ioc), resolver_(ioc) {
		resolver_.async_resolve(host, port, std::bind(&Client::onResolve, this,
			std::placeholders::_1, std::placeholders::_2));
	}

	void onResolve(error_code ec, tcp::resolver::results_type endpoints) {
		if (ec) {
			printf("resolve error: %s\n", ec.message().c_str());
		}
		else {
			boost::asio::async_connect(socket_, endpoints, std::bind(&Client::onConnect,
				this, std::placeholders::_1, std::placeholders::_2));
		}
	}

	void onConnect(error_code ec, tcp::endpoint endpoint) {
		if (ec) {
			std::cout << "Connect failed: " << ec.message() << std::endl;
			socket_.close();
		}
		else {
			doWrite();
		}
	}

	void doWrite() {
		std::size_t len = 0;
		do {
			std::cout << "Enter message: ";
			std::cin.getline(cin_buf_, BUF_SIZE);
			len = strlen(cin_buf_);
		} while (len == 0);

		cin_buf_[len++] = '\n';

		boost::asio::async_write(socket_, boost::asio::buffer(cin_buf_, len),
			std::bind(&Client::onWrite, this, std::placeholders::_1));
	}

	void onWrite(error_code ec) {
		if (!ec) {
			std::cout << "reply is ";
			socket_.async_read_some(boost::asio::buffer(buf_), std::bind(&Client::onRead, this,
				std::placeholders::_1, std::placeholders::_2));
		}
	}

	void onRead(error_code ec, std::size_t len) {
		if (!ec) {
			std::cout.write(buf_.data(), len);

			doWrite();
		}
	}

private:
	tcp::socket socket_;
	tcp::resolver resolver_;

	char cin_buf_[BUF_SIZE];
	std::array<char, BUF_SIZE> buf_;
};

void startAsyncTcpEchoClient() {
	boost::asio::io_context ioc;

	Client client(ioc, host_ip, std::to_string(port));

	ioc.run();
}