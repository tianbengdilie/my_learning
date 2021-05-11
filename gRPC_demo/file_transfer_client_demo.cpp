#include "client_demo.h"

#include "file_transfer.grpc.pb.h"

using namespace filetransfer;

#include <string>
#include <memory>
#include <iostream>
#include <random>

using namespace std;

#include "grpcpp/create_channel.h"
#include "grpcpp/security/credentials.h"

void fileTransfer_demo() {
	const string savepath = "C:\\Users\\tian\\Documents\\Visual Studio 2017\\Project\\Learning\\gRPC_demo\\test_dir\\target.dll";
	const string address = "localhost:50051";

	shared_ptr<grpc::Channel> chan = grpc::CreateChannel(address, grpc::InsecureChannelCredentials());
	unique_ptr<FileServer::Stub> stub = FileServer::NewStub(chan);

	int32_t blockCnt, blockSize, fileSize;

	{
		grpc::ClientContext ctx;
		FileName filename;
		FileMetadata md;
		auto status = stub->getMetaData(&ctx, filename, &md);
		if (!status.ok()) {
			cout << "rpc server get error" << endl;
			exit(0);
		}

		blockCnt = md.blockcount();
		blockSize = md.blocksize();
		fileSize = md.filesize();

		printf("file[%s] blockCnt[%d] blockSize[%d] fileSize[%d]\n", savepath.c_str(), blockCnt, blockSize, fileSize);
	}

	vector<bool> bitmap(blockCnt, false);

	{
		// 预分配空间
		HANDLE file = CreateFile(savepath.c_str(), GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
		LARGE_INTEGER fs;
		fs.QuadPart = fileSize;
		::SetFilePointerEx(file, fs, 0, FILE_BEGIN);
		::SetEndOfFile(file);
		::SetFilePointer(file, 0, 0, FILE_BEGIN);
		CloseHandle(file);
	}

	FILE * pFile = nullptr;
	auto en = fopen_s(&pFile, savepath.c_str(), "wbR");

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, blockCnt - 1);

	while (blockCnt) {
		SliceRequest req;
		Slice resp;

		// 随机获取一个未曾获取的块
		int idx = -1;
		while (true) {
			auto tmp = dist(mt);
			if (bitmap[tmp] == false) {
				idx = tmp;
				break;
			}
		}
		req.set_idx(idx);
		req.set_offset(0);

		grpc::ClientContext ctx;
		auto status = stub->getSlice(&ctx, req, &resp);

		if (!status.ok()) {
			cout << "error get file slice" << endl;
			exit(0);
		}
		else {
			fseek(pFile, resp.idx() * blockSize, SEEK_SET);
			auto len = fwrite(resp.data().c_str(), sizeof(char), resp.length(), pFile);
			if (len != resp.length()) {
				cout << "error written len no equal with accept" << endl;
				exit(0);
			}

			bitmap[idx] = true;
			blockCnt--;
		}
	}

	cout << "completed accept file" << endl;
}