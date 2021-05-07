#pragma once

#define _WIN32_WINDOWS 0x0601
#define _WINSOCK_DEPRECATED_NO_WARNINGS

constexpr size_t BUF_SIZE = 4096;
constexpr unsigned short port = 10114;
constexpr const char * host_ip = "localhost";


void startSyncTcpEchoServer();
void startAsyncTcpEchoServer();
void startSyncTcpEchoClient();
void startAsyncTcpEchoClient();

void startAsyncTcpWriteFileServer();

void transferFile();
void randomTransferFile();
