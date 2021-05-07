#include <thread>
#include <vector>
#include <chrono>
using namespace std;

#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/sinks/basic_file_sink.h>

constexpr const char* LoggerName = "basic_logger";

void loggingThread();

int main() {
	spdlog::flush_every(chrono::seconds(3));

	auto logger = spdlog::create_async<spdlog::sinks::basic_file_sink_mt>(LoggerName, "basic-log.txt");
	spdlog::get("basic_logger")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");

	vector<thread> ths;
	for (int i = 0; i < 10; ++i) {
		ths.emplace_back(&loggingThread);
	}

	for (auto& th : ths) th.join();
}

void loggingThread() {
	for (int i = 0; i < 10; ++i) {
		spdlog::get(LoggerName)->info("logger for {0}", i);
	}
}