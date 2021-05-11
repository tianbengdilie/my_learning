#include "toturial_impl.h"

#pragma comment (lib, "ws2_32.lib") 

#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

#include "helper.h"

void official_demo() {
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