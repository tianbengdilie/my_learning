#include "toturial_impl.h"

#pragma comment (lib, "ws2_32.lib") 

#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

#include <fstream>
#include <sstream>

string getContent(string db_path) {
	std::ifstream db_file(db_path);
	if (!db_file.is_open()) {
		std::cout << "Failed to open " << db_path << std::endl;
		return "";
	}
	std::stringstream db;
	db << db_file.rdbuf();
	return db.str();
}

int main() {
	string db_path = ".\\route_guide_db.json";
	string db_content = getContent(db_path);
	std::string server_address("0.0.0.0:50051");

	RouteGuideImpl service(db_content);

	grpc::ServerBuilder builder;
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	builder.RegisterService(&service);
	std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
	std::cout << "Server listening on " << server_address << std::endl;
	server->Wait();
}