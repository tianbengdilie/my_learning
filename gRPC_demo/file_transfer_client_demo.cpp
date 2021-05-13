#include "client_demo.h"

#include "file_transfer.grpc.pb.h"

using namespace filetransfer;

#include <string>
#include <memory>
#include <iostream>
#include <random>
#include <queue>

using namespace std;

#include "grpcpp/create_channel.h"
#include "grpcpp/security/credentials.h"

const string savepath = "C:\\Users\\tian\\Documents\\Visual Studio 2017\\Project\\Learning\\gRPC_demo\\test_dir\\target.dll";
const string address = "localhost:50051";

struct FileSliceContext {
	shared_ptr<grpc::ClientContext> ctx;
	shared_ptr<grpc::CompletionQueue> cq;
	shared_ptr<Slice> slice;
	shared_ptr<grpc::Status> status;
	int tag;
};

void fileTransfer_asyn_demo() {
	shared_ptr<grpc::Channel> chan = grpc::CreateChannel(address, grpc::InsecureChannelCredentials());
	unique_ptr<FileServer::Stub> stub = FileServer::NewStub(chan);

	int64_t blockCnt, blockSize, fileSize;

	{
		grpc::ClientContext ctx;
		FileName filename;

		grpc::CompletionQueue cq;
		unique_ptr<grpc::ClientAsyncResponseReader<FileMetadata>> rpc(stub->AsyncgetMetaData(&ctx, filename, &cq));

		FileMetadata md;
		grpc::Status status;
		// 通过唯一标志，请求回复
		rpc->Finish(&md, &status, (void*)1024);

		void* tag;
		bool ok = false;
		// 阻塞，知道rpc完成
		cq.Next(&tag, &ok);

		if(tag != (void*) 1024 || !ok) {
			cout << "rpc server get error" << endl;
			exit(0);
		}

		blockCnt = md.blockcount();
		blockSize = md.blocksize();
		fileSize = md.filesize();

		printf("file[%s] blockCnt[%d] blockSize[%d] fileSize[%d]\n", savepath.c_str(), blockCnt, blockSize, fileSize);
	}

	//预分配空间	
	{
		HANDLE file = CreateFile(savepath.c_str(), GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
		LARGE_INTEGER fs;
		fs.QuadPart = fileSize;
		::SetFilePointerEx(file, fs, 0, FILE_BEGIN);
		::SetEndOfFile(file);
		::SetFilePointer(file, 0, 0, FILE_BEGIN);
		CloseHandle(file);
	}


	mutex mtx;
	queue<shared_ptr<FileSliceContext>> fileSliceRequestList;

	thread requestTh([blockCnt, &mtx, &fileSliceRequestList, &stub]() {
		for (int i = 0; i < blockCnt; ++i) {
			shared_ptr<FileSliceContext> fsCtx = make_shared<FileSliceContext>();
			fsCtx->ctx = make_shared<grpc::ClientContext>();
			fsCtx->cq = make_shared<grpc::CompletionQueue>();
			SliceRequest req;
			req.set_idx(i);
			req.set_offset(0);

			shared_ptr<grpc::ClientAsyncResponseReader<Slice>> rpc(stub->PrepareAsyncgetSlice(fsCtx->ctx.get(), req, fsCtx->cq.get()));

			rpc->StartCall();

			// 调用finish才算是真正开始发送请求
			shared_ptr<Slice> slice = make_shared<Slice>();;
			shared_ptr<grpc::Status> status = make_shared<grpc::Status>();;
			rpc->Finish(slice.get(), status.get(), (void*)(i + 1));

			fsCtx->slice = slice;
			fsCtx->status = status;
			fsCtx->tag = i + 1;

			// 保证不要建立过多的连接
			while (fileSliceRequestList.size() > 500);

			lock_guard<mutex> lock(mtx);
			fileSliceRequestList.push(fsCtx);
		}
	});

	thread writeTh([blockSize, blockCnt, &mtx, &fileSliceRequestList]() {
		FILE * file = nullptr;
		fopen_s(&file, savepath.c_str(), "wbR");

		for (int i = 0; i < blockCnt; ++i) {

			shared_ptr<Slice> slice;

			while (fileSliceRequestList.empty());

			shared_ptr<FileSliceContext> fsCtx(nullptr);
			{
				lock_guard<mutex> lock(mtx);
				fsCtx = fileSliceRequestList.front();
				fileSliceRequestList.pop();
			}

			void * tag = nullptr;
			bool flag = false;
			fsCtx->cq->Next(&tag, &flag);

			if (!fsCtx->status->ok()) {
				cout << "status ok is false" << endl;
				exit(0);
			}
			if (tag != (void*)(fsCtx->tag)) {
				cout << "tag is diff" << endl;
				exit(0);
			}

			slice = fsCtx->slice;
			fseek(file, slice->idx() * blockSize, SEEK_SET);
			auto resp_len = slice->length();

			auto len = fwrite(slice->data().c_str(), sizeof(char), resp_len, file);
			if (len != resp_len) {
				cout << "error, write len no equal with resp" << endl;
				exit(0);
			}
		}
	});

	requestTh.join();
	writeTh.join();


}

void fileTransfer_demo() {

	shared_ptr<grpc::Channel> chan = grpc::CreateChannel(address, grpc::InsecureChannelCredentials());
	unique_ptr<FileServer::Stub> stub = FileServer::NewStub(chan);

	int64_t blockCnt, blockSize, fileSize;

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