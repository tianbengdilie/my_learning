#include "asio_demo.h"

#include <boost/asio.hpp>
#include <memory>
#include <array>
#include <iostream>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
	Session(tcp::socket socket) : socket_(std::move(socket)) {}

	void Start() {
		DoRead();
	}

	void DoRead() {
		// 用于保护当前实例的生命周期
		std::shared_ptr<Session> self(shared_from_this());

		socket_.async_read_some(
			boost::asio::buffer(buffer_),
			[this, self](boost::system::error_code ec, std::size_t len) {
			if (!ec) {
				printf("receive content[%s]\n", std::string(buffer_.data(), buffer_.data() + len).c_str());
				DoWrite(len);
			}
		});
	}

	void DoWrite(std::size_t len) {
		// 用于保护当前实例的生命周期
		std::shared_ptr<Session> self(shared_from_this());

		boost::asio::async_write(
			socket_,
			boost::asio::buffer(buffer_, len),
			[this, self](boost::system::error_code ec, std::size_t len) {
			printf("send content[%s]\n", std::string(buffer_.data(), buffer_.data() + len).c_str());
			if (!ec) {
			DoRead();
		}
		});
	}

private:
	tcp::socket socket_;
	std::array<char, BUF_SIZE> buffer_;
};

class Server {
public:
	Server(boost::asio::io_context & ioc, std::uint16_t port) :
		acceptor_(ioc, tcp::endpoint(tcp::v4(), port)) {
		DoAccept();
	}

private:
	void DoAccept() {
		acceptor_.async_accept(
			[this](boost::system::error_code ec, tcp::socket socket) {
			if (!ec) {
				std::cout << "accept a new connect\n";
				std::make_shared<Session>(std::move(socket))->Start();
			}
			DoAccept();
		});
	}

private:
	tcp::acceptor acceptor_;
};

void startAsyncTcpEchoServer() {
	boost::asio::io_context ioc;
	Server server(ioc, port);

	ioc.run();
}