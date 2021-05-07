#include <iostream>
#include <thread>
#include <future>
#include <sstream>
#include <functional>
using namespace std;

#include <zmq.hpp>
#include <zmq_addon.hpp>

void example_push_pull() {
	zmq::context_t ctx;
	zmq::socket_t sender(ctx, zmq::socket_type::push);
	zmq::socket_t listener(ctx, zmq::socket_type::pull);
	sender.bind("tcp://127.0.0.1:12306");
	const std::string last_endpoint =
		sender.get(zmq::sockopt::last_endpoint);
	std::cout << "Connecting to "
		<< last_endpoint << std::endl;
	listener.connect(last_endpoint);

	std::array<zmq::const_buffer, 2> send_msgs = {
		zmq::str_buffer("foo"),
		zmq::str_buffer("bar!")
	};
	if (!zmq::send_multipart(sender, send_msgs))
		return;

	std::vector<zmq::message_t> recv_msgs;
	const auto ret = zmq::recv_multipart(
		listener, std::back_inserter(recv_msgs));
	if (!ret)
		return;
	for (auto& msg : recv_msgs) {
		std::cout << msg.str() << std::endl;		// zmq::message_t [size 003] ( foo)
		std::cout << msg.to_string() << std::endl;	// foo
	}
}

const std::string pub_sub_addr = "tcp://127.0.0.1:5557";
//const std::string pub_sub_addr = "inproc://localsock";
//const std::string pub_sub_addr = "inproc://#1";

string get_str_threadid() {
	ostringstream sout;
	sout.str("");
	sout << this_thread::get_id();
	return sout.str();
}

void PublisherThread(zmq::context_t *ctx) {
	//  Prepare publisher
	zmq::socket_t publisher(*ctx, zmq::socket_type::pub);
	publisher.bind(pub_sub_addr);

	// Give the subscribers a chance to connect, so they don't lose any messages
	std::this_thread::sleep_for(std::chrono::milliseconds(20));

	while (true) {
		//  Write three messages, each with an envelope and content
		publisher.send(zmq::str_buffer("A"), zmq::send_flags::sndmore);
		publisher.send(zmq::str_buffer("Message in A envelope"));
		publisher.send(zmq::str_buffer("B"), zmq::send_flags::sndmore);
		publisher.send(zmq::str_buffer("Message in B envelope"));
		publisher.send(zmq::str_buffer("C"), zmq::send_flags::sndmore);
		publisher.send(zmq::str_buffer("Message in C envelope"));

		this_thread::sleep_for(chrono::milliseconds(300));
	}
}

void SubscriberThread1(zmq::context_t *ctx) {
	//  Prepare subscriber
	zmq::socket_t subscriber(*ctx, zmq::socket_type::sub);
	subscriber.connect(pub_sub_addr);

	//  Thread2 opens "A" and "B" envelopes
	subscriber.set(zmq::sockopt::subscribe, "A");
	subscriber.set(zmq::sockopt::subscribe, "B");

	while (1) {
		// Receive all parts of the message
		std::vector<zmq::message_t> recv_msgs;
		zmq::recv_result_t result =
			zmq::recv_multipart(subscriber, std::back_inserter(recv_msgs));
		assert(result && "recv failed");
		assert(*result == 2);

		printf("Thread2: [%s] %s\n", recv_msgs[0].to_string().data(), recv_msgs[1].to_string().data());
	}
}

void SubscriberThread2(zmq::context_t *ctx) {
	//  Prepare our context and subscriber
	zmq::socket_t subscriber(*ctx, zmq::socket_type::sub);
	subscriber.connect(pub_sub_addr);

	//  Thread3 opens ALL envelopes
	subscriber.set(zmq::sockopt::subscribe, "");

	while (1) {
		// Receive all parts of the message
		std::vector<zmq::message_t> recv_msgs;
		zmq::recv_result_t result =
			zmq::recv_multipart(subscriber, std::back_inserter(recv_msgs));
		assert(result && "recv failed");
		assert(*result == 2);

		printf("Thread3: [%s] %s\n", recv_msgs[0].to_string().data(), recv_msgs[1].to_string().data());
	}
}

void example_singlepub_multisub() {
	/*
	 * No I/O threads are involved in passing messages using the inproc transport.
	 * Therefore, if you are using a ØMQ context for in-process messaging only you
	 * can initialise the context with zero I/O threads.
	 *
	 * Source: http://api.zeromq.org/4-3:zmq-inproc
	 */
	zmq::context_t ctx(1);

	auto thread0 = std::async(std::launch::async, PublisherThread, &ctx);

	// Give the publisher a chance to bind, since inproc requires it
	std::this_thread::sleep_for(std::chrono::milliseconds(10));

	auto thread2 = std::async(std::launch::async, SubscriberThread1, &ctx);
	auto thread3 = std::async(std::launch::async, SubscriberThread2, &ctx);

	thread0.wait();
	thread2.wait();
	thread3.wait();

	/*
	 * Output:
	 *   An infinite loop of a mix of:
	 *     Thread2: [A] Message in A envelope
	 *     Thread2: [B] Message in B envelope
	 *     Thread3: [A] Message in A envelope
	 *     Thread3: [B] Message in B envelope
	 *     Thread3: [C] Message in C envelope
	 */
}

void example_multipub_singlesub() {
	zmq::context_t ctx(1);

	function<void(zmq::context_t*, int)> pub_func = [](zmq::context_t* ctx, int port) {
		zmq::socket_t pub(*ctx, zmq::socket_type::pub);
		pub.bind("tcp://127.0.0.1:" + to_string(port));

		string tid = get_str_threadid();
		char buff[128];
		sprintf_s(buff, "message from %s", tid.data());

		while (true) {
			pub.send(zmq::str_buffer("topic"), zmq::send_flags::sndmore);
			pub.send(zmq::mutable_buffer(buff, strlen(buff)), zmq::send_flags::none);

			this_thread::sleep_for(chrono::milliseconds(500));
		}
	};

	function<void(zmq::context_t*, vector<int>&)> sub_func = [](zmq::context_t* ctx, vector<int>& ports) {
		zmq::socket_t sub(*ctx, zmq::socket_type::sub);
		for (auto& port : ports) {
			sub.connect("tcp://127.0.0.1:" + to_string(port));
		}

		sub.set(zmq::sockopt::subscribe, "");

		while (true) {
			vector<zmq::message_t> buffs;
			auto ret = zmq::recv_multipart(sub, back_inserter(buffs));
			cout << buffs[0].to_string().data() << " : " << buffs[1].to_string().data() << endl;
		}
	};

	vector<int> ports{ 12222,12223,12224 };
	auto th1 = async(pub_func, &ctx, ports[0]);
	auto th2 = async(pub_func, &ctx, ports[1]);
	auto th3 = async(pub_func, &ctx, ports[2]);

	auto th4 = async(sub_func, &ctx, ref(ports));

	th1.wait();
	th2.wait();
	th3.wait();
	th4.wait();
}

int main() {
	//zmq::context_t ctx(1);
	//zmq::socket_t sub(ctx, zmq::socket_type::sub);
	//sub.connect("tcp://127.0.0.1:12306");
	//sub.connect("tcp://127.0.0.1:12305");
	//sub.connect("tcp://127.0.0.1:12304");
	//sub.connect("tcp://127.0.0.1:12303");
	//sub.connect("tcp://127.0.0.1:12302");

	//sub.set(zmq::sockopt::subscribe, "");

	//while (true) {
	//	vector<zmq::message_t> buffs;
	//	auto ret = zmq::recv_multipart(sub, back_inserter(buffs));
	//	cout << buffs[0].to_string().data() << " : " << buffs[1].to_string().data() << endl;
	//}

	zmq::context_t ctx(1);
	zmq::socket_t sub(ctx, zmq::socket_type::sub);
	sub.set(zmq::sockopt::subscribe, "");

	sub.connect("tcp://127.0.0.1:12301");

	while (true) {
		vector<zmq::message_t> buffs;
		auto ret = zmq::recv_multipart(sub, back_inserter(buffs));
		cout << buffs[1].to_string() << endl;
	}

}