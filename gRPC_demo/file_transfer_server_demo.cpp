#include "server_demo.h"

#include "file_transfer.grpc.pb.h"
#include <grpcpp/server_builder.h>
#include <grpcpp/security/credentials.h>

#include <string>
#include <iostream>

using namespace std;

using grpc::Status;
using grpc::ServerContext;

using namespace filetransfer;

constexpr int32_t BlockSize = 4096;

class FileServerImpl : public filetransfer::FileServer::Service {
public:
	explicit FileServerImpl(const string& filepath) {
		auto en = fopen_s(&pFile_, filepath.c_str(), "rbR");
		if (en != 0) {
			cout << "open file, error_no : " << en << endl;
			exit(0);
		}
	}

	virtual Status getSlice(ServerContext* ctx, const SliceRequest* req, Slice* resp) override;
	virtual Status getMetaData(ServerContext* context, const FileName* request, FileMetadata* response) override;
private:
	FILE *pFile_;
	mutex mtx_;
};

Status FileServerImpl::getSlice(ServerContext * ctx, const SliceRequest * req, Slice * resp)
{
	const int32_t idx = req->idx();
	const int32_t offset = req->offset();

	const long long rightBound = (idx + 1) * BlockSize;
	const long long leftBound = idx * BlockSize + offset;

	lock_guard<mutex> lock(mtx_);
	resp->set_idx(idx);
	resp->set_offset(offset);

	long long len = rightBound - leftBound;
	vector<char> buff(len);
	fseek(pFile_, leftBound, SEEK_SET);
	len = fread(buff.data(), sizeof(char), len, pFile_);

	resp->set_data(string(buff.data(), len));
	resp->set_length(len);

	//printf("slice idx[%d] left[%d] len[%ld]\n", resp->idx(), leftBound, resp->length());

	return Status::OK;
}

Status FileServerImpl::getMetaData(ServerContext * context, const FileName * request, FileMetadata * response)
{
	response->set_blocksize(BlockSize);
	{
		lock_guard<mutex> lock(mtx_);
		fseek(pFile_, 0, SEEK_END);
		int32_t size = ftell(pFile_);
		response->set_filesize(size);
		response->set_blockcount((size + BlockSize - 1) / BlockSize);
		fseek(pFile_, 0, SEEK_SET);
	}

	return Status::OK;
}

void fileServer_demo() {
	const string sourcepath = "C:\\Users\\tian\\Documents\\Visual Studio 2017\\Project\\Learning\\gRPC_demo\\test_dir\\source.dll";
	const string address = "0.0.0.0:50051";

	FileServerImpl fileServer(sourcepath);

	grpc::ServerBuilder builder;
	builder.AddListeningPort(address, grpc::InsecureServerCredentials());
	builder.RegisterService(&fileServer);

	unique_ptr<grpc::Server> server(builder.BuildAndStart());
	cout << "server listen on " << address << endl;
	server->Wait();
}